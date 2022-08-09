#include "CollisionSystem.hpp"

#include "../Components_Events.hpp"

#include <assert.h>




const Usize MAX_ENTITIES_IN_TREE = 16;
const Usize SUBTREE_AMOUNT = 4;

enum BoxOrCircle
{
    Box,
    Circle
};


struct QuadTree
{
    Vector2f pos; // center point in world space
    QuadTree *sub_trees[SUBTREE_AMOUNT]; // 0th subtree starts at top right going counter-clockwise

    Usize entity_count;
    Entity entity_list[MAX_ENTITIES_IN_TREE];

    Transform transform_list[MAX_ENTITIES_IN_TREE];
    Vector2i size_list[MAX_ENTITIES_IN_TREE];
    BoxOrCircle boc_list[MAX_ENTITIES_IN_TREE];
};



static bool is_top_right(Vector2f *tree_pos, Transform *T_e, Vector2i s_e, BoxOrCircle boc_e)
{
    //TODO(Johan) finish
}



static void init_root(QuadTree *root)
{
    *root = {
        .sub_trees = {},
        .entity_count = 0,
    };

    for (int i = 0; i < MAX_ENTITIES_IN_TREE; ++i)
    {
        root->entity_list[i] = ENTITY_NULL;
    }
}

static void add_entity_to_tree(QuadTree *tree, top_memory_arena *arena, Entity e, Transform t_e, Vector2i s_e, BoxOrCircle boc_e);


static void spill_tree(QuadTree *tree, top_memory_arena *arena)
{
    for (int i = 0; i < SUBTREE_AMOUNT; ++i)
    {
        tree->sub_trees[i] = Arena::top_alloc<QuadTree>(arena);
        *tree->sub_trees[i] = {
            .sub_trees = {},
            .entity_count = 0,    
        };

        for (int j = 0; j < MAX_ENTITIES_IN_TREE; ++j)
        {
            tree->sub_trees[i]->entity_list[j] = ENTITY_NULL;
        }
    }

    for (int i = 0; i < MAX_ENTITIES_IN_TREE; ++i)
    {
        Entity e = tree->entity_list[i];

        Transform t_e     = tree->transform_list[i];
        Vector2i s_e      = tree->size_list[i];
        BoxOrCircle boc_e = tree->boc_list[i];

        if (t_e.pos.x > tree->pos.x && t_e.pos.y < tree->pos.y)
        {
            add_entity_to_tree(tree->sub_trees[0], arena, e, t_e, s_e, boc_e);
        }
        if (t_e.pos.x < tree->pos.x && t_e.pos.y < tree->pos.y)
        {
            add_entity_to_tree(tree->sub_trees[1], arena, e, t_e, s_e, boc_e);
        }
        if (t_e.pos.x < tree->pos.x && t_e.pos.y > tree->pos.y)
        {
            add_entity_to_tree(tree->sub_trees[2], arena, e, t_e, s_e, boc_e);
        }
        if (t_e.pos.x > tree->pos.x && t_e.pos.y > tree->pos.y)
        {
            add_entity_to_tree(tree->sub_trees[3], arena, e, t_e, s_e, boc_e);
        }
    }
    
    for (int i = 0; i < MAX_ENTITIES_IN_TREE; ++i)
    {
        tree->entity_list[i] = ENTITY_NULL;
    }
} 


static void add_entity_to_tree(QuadTree *tree, top_memory_arena *arena, Entity e, Transform t_e, Vector2i s_e, BoxOrCircle boc_e)
{
    if (tree->entity_count < MAX_ENTITIES_IN_TREE)
    {
        tree->entity_list[tree->entity_count]    = e;
        tree->transform_list[tree->entity_count] = t_e;
        tree->size_list[tree->entity_count]      = s_e;
        tree->boc_list[tree->entity_count]       = boc_e;
        ++tree->entity_count;
    }
    else if (tree->sub_trees[0] == NULL)
    {
        spill_tree(tree, arena);
    }



}





void CollisionSystem::update(Iter *it)
{
    Group *box_group = Ecs::get_group<Transform, Velocity, BoxCollider, SpriteComponent>(it->registry); 
    Transform *box_transform_list    = Ecs::get_comp_array<Transform>(box_group, 0);
    Velocity *box_velocity_list      = Ecs::get_comp_array<Velocity>(box_group, 1);
    BoxCollider *box_collider_list   = Ecs::get_comp_array<BoxCollider>(box_group, 2);
    SpriteComponent *box_sprite_list = Ecs::get_comp_array<SpriteComponent>(box_group, 3);


    Group *circle_group = Ecs::get_group<Transform, Velocity, CircleCollider, SpriteComponent>(it->registry); 
    Transform *circle_transform_list     = Ecs::get_comp_array<Transform>(circle_group, 0);
    Velocity *circle_velocity_list       = Ecs::get_comp_array<Velocity>(circle_group, 1);
    CircleCollider *circle_collider_list = Ecs::get_comp_array<CircleCollider>(circle_group, 2);
    SpriteComponent *circle_sprite_list  = Ecs::get_comp_array<SpriteComponent>(circle_group, 3);



    QuadTree *root = Arena::top_alloc<QuadTree>(it->view_arena);

    init_root(root); //TODO(Johan): finish


}


