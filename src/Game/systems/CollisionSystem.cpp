#include "CollisionSystem.hpp"

#include "../Components_Events.hpp"

#include <assert.h>




const Usize MAX_ENTITIES_IN_TREE = 256;
const Usize SUBTREE_AMOUNT = 4;

enum BoxOrCircle
{
    Box,
    Circle
};


struct QuadTree
{
    Vector2f pos;
    Vector2f size;

    QuadTree *sub_trees[SUBTREE_AMOUNT]; // 0th tree starts at top right going counter clockwise

    Usize entity_count;
    Entity *entity_list;
    Transform *t_list;
    BoxCollider *bc_list;
    CircleCollider *cc_list;
};

static void add_entity_to_tree(QuadTree *tree, top_memory_arena *arena, Entity e, const Transform *t_e, const BoxCollider *bc_e, const CircleCollider *cc_e);


static void add_entity_to_intersecting_trees(QuadTree *parent_tree, top_memory_arena *arena, Entity e, const Transform *t_e, const BoxCollider *bc_e, const CircleCollider *cc_e)
{

    Vector2f size = {0.0f, 0.0f};

    if (bc_e != NULL)
    {
        size = bc_e->size;

    }
    else if (cc_e != NULL)
    {
        size = {cc_e->radius * 2, cc_e->radius * 2};
    }


    bool intersects_subtree_0 = t_e->pos.x + (size.x / 2) * t_e->scale.x  > parent_tree->pos.x 
        && t_e->pos.y - (size.y / 2) * t_e->scale.y < parent_tree->pos.y;

    bool intersects_subtree_1 = t_e->pos.x - (size.x / 2) * t_e->scale.x  < parent_tree->pos.x 
        && t_e->pos.y - (size.y / 2) * t_e->scale.y < parent_tree->pos.y;

    bool intersects_subtree_2 = t_e->pos.x - (size.x / 2) * t_e->scale.x  < parent_tree->pos.x 
        && t_e->pos.y + (size.y / 2) * t_e->scale.y > parent_tree->pos.y;

    bool intersects_subtree_3 = t_e->pos.x + (size.x / 2) * t_e->scale.x  > parent_tree->pos.x 
        && t_e->pos.y + (size.y / 2) * t_e->scale.y > parent_tree->pos.y;


    if (intersects_subtree_0)
        add_entity_to_tree(parent_tree->sub_trees[0], arena, e, t_e, bc_e, cc_e);
    if (intersects_subtree_1)
        add_entity_to_tree(parent_tree->sub_trees[1], arena, e, t_e, bc_e, cc_e);
    if (intersects_subtree_2)
        add_entity_to_tree(parent_tree->sub_trees[2], arena, e, t_e, bc_e, cc_e);
    if (intersects_subtree_3)
        add_entity_to_tree(parent_tree->sub_trees[3], arena, e, t_e, bc_e, cc_e);       
}




static void spill_tree(QuadTree *tree, top_memory_arena *arena)
{
        Vector2f pos0 = {.x = tree->pos.x + tree->size.x / 2, .y = tree->pos.y - tree->size.y / 2};
        Vector2f pos1 = {.x = tree->pos.x - tree->size.x / 2, .y = tree->pos.y - tree->size.y / 2};
        Vector2f pos2 = {.x = tree->pos.x - tree->size.x / 2, .y = tree->pos.y + tree->size.y / 2};
        Vector2f pos3 = {.x = tree->pos.x + tree->size.x / 2, .y = tree->pos.y + tree->size.y / 2};


        Vector2f size = {.x = tree->size.x / 2, .y = tree->size.y}; 

    // init sub_trees
    for (int i = 0; i < SUBTREE_AMOUNT; ++i)
    {
        tree->sub_trees[i] = Arena::top_alloc<QuadTree>(arena);
    }
        *tree->sub_trees[0] = {
            .pos = pos0,
            .size = size,
            .sub_trees = {},
            .entity_count = 0,
        };
        *tree->sub_trees[1] = {
            .pos = pos1,
            .size = size,
            .sub_trees = {},
            .entity_count = 0,
        };
        *tree->sub_trees[2] = {
            .pos = pos2,
            .size = size,
            .sub_trees = {},
            .entity_count = 0,
        };
        *tree->sub_trees[3] = {
            .pos = pos3,
            .size = size,
            .sub_trees = {},
            .entity_count = 0,
        };   

    for (int i = 0; i < SUBTREE_AMOUNT; ++i)
    {
        tree->sub_trees[i]->entity_list = Arena::top_alloc<Entity>(arena, MAX_ENTITIES_IN_TREE);
        tree->sub_trees[i]->t_list      = Arena::top_alloc<Transform>(arena, MAX_ENTITIES_IN_TREE);
        tree->sub_trees[i]->bc_list     = Arena::top_alloc<BoxCollider>(arena, MAX_ENTITIES_IN_TREE);
        tree->sub_trees[i]->cc_list     = Arena::top_alloc<CircleCollider>(arena, MAX_ENTITIES_IN_TREE);

#ifdef _DEBUG
        for (int j = 0; j < MAX_ENTITIES_IN_TREE; ++j)
        {
            tree->sub_trees[i]->entity_list[j] = ENTITY_NULL;
        }
#endif

    }

    for (int i = 0; i < tree->entity_count; ++i)
    {
        add_entity_to_intersecting_trees(tree, arena, tree->entity_list[i], &tree->t_list[i], &tree->bc_list[i], &tree->cc_list[i]);
    }
}




static void add_entity_to_tree(QuadTree *tree, top_memory_arena *arena, Entity e, const Transform *t_e, const BoxCollider *bc_e, const CircleCollider *cc_e)
{
    if (tree->entity_count < MAX_ENTITIES_IN_TREE)
    {
        tree->entity_list[tree->entity_count] = e;
        tree->t_list[tree->entity_count] = *t_e;
        if (bc_e != NULL)
            tree->bc_list[tree->entity_count] = *bc_e;
        if (cc_e != NULL)        
            tree->cc_list[tree->entity_count] = *cc_e;
        tree->entity_count += 1;
    }
    else if (tree->sub_trees[0] == NULL)
    {
        spill_tree(tree, arena);
        add_entity_to_intersecting_trees(tree, arena, e, t_e, bc_e, cc_e);
    }
    else
    {
        add_entity_to_intersecting_trees(tree, arena, e, t_e, bc_e, cc_e);
    }
}


static void init_root(QuadTree *root, top_memory_arena *arena)
{
    *root = {
        .pos = {0.0f, 0.0f},
        .size = {1'000'000.0f , 1'000'000.0f},
        .sub_trees = {},
        .entity_count = 0,
    };
    
    root->entity_list = Arena::top_alloc<Entity>(arena, MAX_ENTITIES_IN_TREE);
    root->t_list      = Arena::top_alloc<Transform>(arena, MAX_ENTITIES_IN_TREE);
    root->bc_list     = Arena::top_alloc<BoxCollider>(arena, MAX_ENTITIES_IN_TREE);
    root->cc_list     = Arena::top_alloc<CircleCollider>(arena, MAX_ENTITIES_IN_TREE);

#ifdef _DEBUG
    for (int i = 0; i < MAX_ENTITIES_IN_TREE; ++i)
    {
        root->entity_list[i] = ENTITY_NULL;
    }
#endif
}


static void check_collisions_in_tree(QuadTree *tree, Ecs::Registry *reg)
{
    if (tree->sub_trees[0] != NULL)
    {
        check_collisions_in_tree(tree->sub_trees[0], reg);
        check_collisions_in_tree(tree->sub_trees[1], reg);
        check_collisions_in_tree(tree->sub_trees[2], reg);
        check_collisions_in_tree(tree->sub_trees[3], reg);
    }
    else
    {
        for (I32 i = 0; i < tree->entity_count; ++i)
        {
            Entity *e1            = &tree->entity_list[i];
            Transform *t_e1       = &tree->t_list[i];
            BoxCollider *bc_e1    = &tree->bc_list[i];
            CircleCollider *cc_e1 = &tree->cc_list[i];


            Vector2f size1;
            if (bc_e1->type != ColliderType::Nothing)
            {
                size1 = bc_e1->size;
            }
            else
            {
                float radius = cc_e1->radius;
                size1 = {radius * 2, radius * 2};
            }
            

            for (I32 j = 0; j < tree->entity_count; ++j)
            {
                Entity *e2            = &tree->entity_list[j];
                Transform *t_e2       = &tree->t_list[j];
                BoxCollider *bc_e2    = &tree->bc_list[j];
                CircleCollider *cc_e2 = &tree->cc_list[j];


                if (*e1 == *e2)
                {
                    continue; 
                }  



                Vector2f size2;
                if (bc_e2->type != ColliderType::Nothing)
                {
                    size2 = bc_e2->size;
                }
                else
                {
                    float radius = cc_e2->radius;
                    size2 = {radius * 2, radius * 2};
                }

                float e1_left_side_x = t_e1->pos.x - (size1.x / 2) * t_e1->scale.x;
                float e2_left_side_x = t_e2->pos.x - (size2.x / 2) * t_e2->scale.x;

                float e1_right_side_x = t_e1->pos.x + (size1.x / 2) * t_e1->scale.x;
                float e2_right_side_x = t_e2->pos.x + (size2.x / 2) * t_e2->scale.x;


                bool b1 = e1_left_side_x < e2_right_side_x;
                bool b2 = e1_right_side_x > e2_left_side_x;



                float e1_bot_side_y = t_e1->pos.y + (size1.y / 2) * t_e1->scale.y;
                float e2_bot_side_y = t_e2->pos.y + (size2.y / 2) * t_e2->scale.y;

                float e1_top_side_y = t_e1->pos.y - (size1.y / 2) * t_e1->scale.y;
                float e2_top_side_y = t_e2->pos.y - (size2.y / 2) * t_e2->scale.y;

                bool b3 = e1_top_side_y < e2_bot_side_y;
                bool b4 = e1_bot_side_y > e2_top_side_y;



                if (b1 && b2 && b3 && b4)
                {
                    CollisionEvent ce = {
                        .e1_type = ColliderType::Nothing,
                        .e2_type = ColliderType::Nothing,
                        .e1 = *e1,
                        .e2 = *e2,
                    };

                    Ecs::push_event<CollisionEvent>(reg, &ce);
                }
            }
        }
    }
}
#define PROFILE_FUNCTIONS
#include "../../files/Time.hpp"




void CollisionSystem::update(Iter *it)
{
    BEGIN_PROFILE_BLOCK;

    const Group *box_group = Ecs::get_group<Transform, BoxCollider>(it->registry); 
    const Transform *box_transform_list    = Ecs::get_comp_array<Transform>(box_group, 0);
    const BoxCollider *box_collider_list   = Ecs::get_comp_array<BoxCollider>(box_group, 1);


    const Group *circle_group = Ecs::get_group<Transform, CircleCollider>(it->registry); 
    const Transform *circle_transform_list     = Ecs::get_comp_array<Transform>(circle_group, 0);
    const CircleCollider *circle_collider_list = Ecs::get_comp_array<CircleCollider>(circle_group, 1);



    QuadTree *root = Arena::top_alloc<QuadTree>(it->view_arena);

    init_root(root, it->view_arena);

    for (Usize i = 0; i < box_group->size; ++i)
    {
        add_entity_to_tree(root, it->view_arena, box_group->entity_list[i], &box_transform_list[i], &box_collider_list[i], NULL);
    }


    for (Usize i = 0; i < circle_group->size; ++i)
    {
        add_entity_to_tree(root, it->view_arena, circle_group->entity_list[i], &circle_transform_list[i], NULL, &circle_collider_list[i]);
    }

    check_collisions_in_tree(root, it->registry);

    END_PROFILE_BLOCK;
}


