#include "systems.hpp"

#include "Components_Events.hpp"

#include <math.h>



void AIControllerSystem::update(Iter *it)
{

    const Group *enemy_group = Ecs::get_group<Transform, EnemyAI, FiringComponent>(it->registry);

    const Transform *t_list = Ecs::get_comp_array<Transform>(enemy_group, 0);
    const EnemyAI *Eai_list = Ecs::get_comp_array<EnemyAI>(enemy_group, 1);
    



    const Group *planet_group = Ecs::get_group<Transform, CircleCollider, Planet>(it->registry);


    Transform planet_transform = {};

    if (planet_group->size == 1)
    {
        const Transform *p_t_list = Ecs::get_comp_array<Transform>(planet_group, 0);
        const CircleCollider *p_cc_list = Ecs::get_comp_array<CircleCollider>(planet_group, 1);

        planet_transform = p_t_list[0];
    }


    for (Usize i = 0; i < enemy_group->size; ++i)
    {
        switch (Eai_list[i].ai_state)
        {
            case EnemyAiState::TargetPlanet:
            {
                Entity e = enemy_group->entity_list[i];
                Transform t = t_list[i];
                Transform *t_mut = Ecs::get_component<Transform>(it->registry, e);
                FiringComponent *fc_mut = Ecs::get_component<FiringComponent>(it->registry, e);

                float dx = planet_transform.pos.x - t.pos.x;
                float dy = planet_transform.pos.y - t.pos.y;

                float angle = atan2f(dy, dx);

                t_mut->rot = {cosf(angle), sinf(angle)};

                fc_mut->firing = true;

            } break;

            case EnemyAiState::TargetAlly:
            {

            } break;

            case EnemyAiState::TargetPlayer:
            {

            } break;
        } 
    }
}



#include <math.h>

void AngleSystem::update(Iter *iter)
{
    View<AnglularVelocity> *angle_vel_view = Ecs::get_view<AnglularVelocity, Transform>(iter->registry);

    for (Usize i = 0; i < angle_vel_view->size; ++i)
    {
        Entity e = angle_vel_view->entity_list[i];
        Transform *transform = Ecs::get_component<Transform>(iter->registry, e);
        AnglularVelocity ang_vel = angle_vel_view->comparray[i];


       float angle = atan2f(transform->rot.y, transform->rot.x);

       transform->rot.x = cosf(angle + ang_vel.angleV * iter->Ts);
       transform->rot.y = sinf(angle + ang_vel.angleV * iter->Ts);

    }
}




static const float MOUSE_ZOOM_SCALE_SPEED = 1.3f;


static MousePos anchor;
static bool anchor_check = false;

void CameraController::update(Iter *iter)
{
    if (game_active_camera == ENTITY_NULL)
    {
        return;
    }

    CameraComponent *camera_comp = Ecs::get_component<CameraComponent>(iter->registry, game_active_camera);
    Transform *camera_transform  = Ecs::get_component<Transform>(iter->registry, game_active_camera);

    MousePos mouse_pos = Real::getMousePos();

    //printf("Mouse pos [%.2f, %.2f]\n", 
    //    Real::screen_to_world_x(camera_transform, camera_comp, mouse_pos.x), 
    //    Real::screen_to_world_y(camera_transform, camera_comp, mouse_pos.y));

    // printf("camerapos [x = %f, y = %f, scale_x = %f, scale_y = %f]\n", scene->camera.world_x, scene->camera.world_y, scene->camera.world_scale_x, scene->camera.world_scale_y);
    switch (Real::IsMouseScroll())
    {
        case MOUSE_SCROLL_NONE:
        {
            // left blank
        } break;

        case MOUSE_SCROLL_UP: //TODO(Johan) add zoom clamp to avoid floating point rounding errors.
        {
            Real::zoom(camera_transform, camera_comp, mouse_pos.x, mouse_pos.y, MOUSE_ZOOM_SCALE_SPEED);

        } break;

        case MOUSE_SCROLL_DOWN:
        {
            Real::zoom(camera_transform, camera_comp, mouse_pos.x, mouse_pos.y, 1.0f / MOUSE_ZOOM_SCALE_SPEED);
        } break;
    }

    if (Real::IsMousePressed(VK_MOUSE_BUTTON_MIDDLE))
    {/*
        //TODO(Johan) try to remove anchor_check.
        if (!anchor_check)
        {
            anchor = Real::getMousePos();
            anchor_check = true;
        }

        MousePos mpos = Real::getMousePos();
        
        camera_transform->pos.x -= (mpos.x - anchor.x) / camera_comp->world_scale.x;
        camera_transform->pos.y -= (mpos.y - anchor.y) / camera_comp->world_scale.y;
        anchor = Real::getMousePos();


    */}
    else
    {
        anchor_check = false;
    }
}



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
    Vec2 pos;
    Vec2 size;

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

    Vec2 size = {};

    if (bc_e != nullptr)
    {
        size = bc_e->size;

    }
    else if (cc_e != nullptr)
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
        Vec2 pos0 = {.x = tree->pos.x + tree->size.x / 2, .y = tree->pos.y - tree->size.y / 2};
        Vec2 pos1 = {.x = tree->pos.x - tree->size.x / 2, .y = tree->pos.y - tree->size.y / 2};
        Vec2 pos2 = {.x = tree->pos.x - tree->size.x / 2, .y = tree->pos.y + tree->size.y / 2};
        Vec2 pos3 = {.x = tree->pos.x + tree->size.x / 2, .y = tree->pos.y + tree->size.y / 2};


        Vec2 size = {.x = tree->size.x / 2, .y = tree->size.y}; 

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


        if (bc_e != nullptr)
            tree->bc_list[tree->entity_count] = *bc_e;
        else
            tree->bc_list[tree->entity_count] = {.type = ColliderType::Nothing};
        if (cc_e != nullptr)        
            tree->cc_list[tree->entity_count] = *cc_e;
        else
            tree->cc_list[tree->entity_count] = {.type = ColliderType::Nothing};

        tree->entity_count += 1;
    }
    else if (tree->sub_trees[0] == nullptr)
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
    if (tree->sub_trees[0] != nullptr)
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


            Vec2 size1;
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



                Vec2 size2;
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
                        .e1_type = bc_e1->type != ColliderType::Nothing ? bc_e1->type : cc_e1->type, 
                        .e2_type = bc_e2->type != ColliderType::Nothing ? bc_e2->type : cc_e2->type,
                        .e1 = *e1,
                        .e2 = *e2,
                    };

                    Ecs::push_event<CollisionEvent>(reg, &ce);
                }
            }
        }
    }
}


//#define PROFILE_FUNCTIONS
#include "../files/Time.hpp"




void CollisionSystem::update(Iter *it)
{
    BEGIN_PROFILE_BLOCK();

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
        add_entity_to_tree(root, it->view_arena, box_group->entity_list[i], &box_transform_list[i], &box_collider_list[i], nullptr);
    }


    for (Usize i = 0; i < circle_group->size; ++i)
    {
        add_entity_to_tree(root, it->view_arena, circle_group->entity_list[i], &circle_transform_list[i], nullptr, &circle_collider_list[i]);
    }

    check_collisions_in_tree(root, it->registry);

    END_PROFILE_BLOCK();
}



void DamageSystem::onCollision(Iter *it)
{
    CollisionEvent *event = (CollisionEvent *)it->event;


    if ((event->e1_type & ColliderType::DynamicCollider) && (event->e2_type & (ColliderType::DynamicCollider|ColliderType::StaticCollider)))
    {
        Velocity *vel_mut_e1 = Ecs::get_component<Velocity>(it->registry, event->e1);
        

        vel_mut_e1->v = vel_mut_e1->v * -1.0f;

        if ((event->e1_type & ColliderType::TakesDamageOnCollide) && (event->e2_type & ColliderType::DealsDamageOnCollide))
        {
            HealthComponent *hc_mut_e1 = Ecs::get_component<HealthComponent>(it->registry, event->e1);
            DamageComponent *dc_mut_e2 = Ecs::get_component<DamageComponent>(it->registry, event->e2);

            hc_mut_e1->health -= dc_mut_e2->damage;
        }

    }
    else if (event->e1_type & ColliderType::StaticCollider)
    {
        if ((event->e1_type & ColliderType::TakesDamageOnCollide )&& (event->e2_type & ColliderType::DealsDamageOnCollide))
        {
            HealthComponent *hc_mut_e1 = Ecs::get_component<HealthComponent>(it->registry, event->e1);
            DamageComponent *dc_mut_e2 = Ecs::get_component<DamageComponent>(it->registry, event->e2);

            hc_mut_e1->health -= dc_mut_e2->damage;
        }
    }
}




void EntityCreationSystem::create_player(Iter *iter)
{
    PlayerSpawnEvent *event = (PlayerSpawnEvent *)iter->event; 
    Entity e = Ecs::create_entity(iter->registry);

    
    Ecs::set_component<Transform>(iter->registry, e, {
        event->transform,
    });


    Ecs::set_component<Velocity>(iter->registry, e, {0.0f, 0.0f});
   // Ecs::set_component(iter->curr_registry, e, collision);
    Ecs::set_component<GravityAffected>(iter->registry, e, {});
    Ecs::set_component<MassComponent>(iter->registry, e, {1000.0f});

    Ecs::set_component<MeshComponent>(iter->registry, e, {
        .mesh = event->mesh,
    });

    Ecs::set_component<MaterialComponent>(iter->registry, e, {
        .material = event->material,
    });

    /*Ecs::set_component<BoxCollider>(iter->registry, e ,{
        .type = ColliderType::DynamicCollider|ColliderType::StaticCollider,
        .size = {
            .x = (float)sprite->width,
            .y = (float)sprite->height,
        },  
    });*/

    Ecs::set_component<Player>(iter->registry, e, {});
}


void EntityCreationSystem::create_bullet(Iter *it)
{
    BulletSpawnEvent *event = (BulletSpawnEvent *)it->event;

    Entity e = Ecs::create_entity(it->registry);



    Ecs::set_component<Transform>(it->registry, e, {
        event->transform,
    });


    Ecs::set_component<Velocity>(it->registry, e, {event->vel}); 
    Ecs::set_component<GravityAffected>(it->registry, e, {});
    Ecs::set_component<MassComponent>(it->registry, e, {1000.0f});
   

   
   
    /*Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::DynamicCollider|ColliderType::DealsDamageOnCollide|ColliderType::TakesDamageOnCollide,
        .size = {
            .x = (float)sprite->width,
            .y = (float)sprite->height,
        },     
    });*/

   
    Ecs::set_component<HealthComponent>(it->registry, e, {
        .health = 10.0f,
        .health_regen = 0.0f,
    });

   
    Ecs::set_component<DamageComponent>(it->registry, e, {
        .damage = 5.0f
    });

}


void EntityCreationSystem::create_ai(Iter *it) //TODO(Johan) maybe separate to different functions
{
    AiSpawnEvent *event = (AiSpawnEvent *)it->event;
    Entity e = Ecs::create_entity(it->registry);

    Ecs::set_component<Transform>(it->registry, e, {
        event->transform
    });

    Ecs::set_component<Velocity>(it->registry, e, {
        event->vel,
    });



    /*Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::DynamicCollider|ColliderType::TakesDamageOnCollide,
        .size = {
            .x = (float)sprite->width,
            .y = (float)sprite->height,
        },  
    });*/


    switch (event->ai_type)
    {
        case AIType::Neutral:
        {
            Ecs::set_component<NeutralAI>(it->registry, e, {});
        } break;


        case AIType::Ally:
        {
            Ecs::set_component<AllyAI>(it->registry, e, {});
        } break;


        case AIType::Enemy:
        {
            Ecs::set_component<EnemyAI>(it->registry, e, {});
        } break;        


        case AIType::Hostile:
        {
            Ecs::set_component<HostileAI>(it->registry, e, {});
        } break;    
    }

    Ecs::set_component<HealthComponent>(it->registry, e, {
        .health = event->health,
        .health_regen = event->health_regen,
    });

    Ecs::set_component<FiringComponent>(it->registry, e, {
        .timer = 0.0f,
        .max_time = 0.4f,
        .firing = false,
    });
}


void EntityCreationSystem::create_planet(Iter *it)
{
    PlanetSpawnEvent *event = (PlanetSpawnEvent *)it->event;
    Ecs::Registry *registry = it->registry;
    
    Entity e = Ecs::create_entity(registry);


    Ecs::set_component<Transform>(registry, e, {
        event->transform,
    });


    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});



   /*Ecs::set_component<CircleCollider>(it->registry, e, {
        .type = ColliderType::StaticCollider|ColliderType::TakesDamageOnCollide,
        .radius = (float)sprite->width / 2.0f,
   });*/


    Ecs::set_component<HealthComponent>(registry, e, {
        .health = event->health,
        .health_regen = event->health_regen,
    });

    Ecs::set_component<Planet>(registry, e, {});
}



void FiringSystem::update(Iter *it)
{
    const Group *group = Ecs::get_group<FiringComponent, Transform>(it->registry);

    const FiringComponent *fc_list = Ecs::get_comp_array<FiringComponent>(group, 0);
    const Transform *t_list = Ecs::get_comp_array<Transform>(group, 1);

    for (Usize i = 0; i < group->size; ++i)
    {
        Entity e = group->entity_list[i];
        FiringComponent fc = fc_list[i];
        Transform t = t_list[i];

        if (fc.firing == true)
        {
            FiringComponent *fc_mut = Ecs::get_component<FiringComponent>(it->registry, e);

            float speed = 4000.0f;
            
            if (fc.timer >= fc.max_time)
            {
                BulletSpawnEvent bse = {
                    .transform = {
                        .pos = t.pos + t.rot * 400.0f,
                        .rot = t.rot,
                        .scale = {50.0f, 50.0f, 0.0f},
                    },
                    .mesh = Real::get_mesh("square_mesh"),
                    .material = Real::get_material("ship_material"),
                    .vel = t.rot * speed,
                    .damage = 5.0f,
                };

                Ecs::push_event<BulletSpawnEvent>(it->registry, &bse);
                fc_mut->timer = 0.0f;
            }
            else
            {
                fc_mut->timer += it->Ts;
            }
        }         
    }

}


#include <float.h>
#include <math.h>
const float G = 6.6743E-11f;


// TODO(Johan) make faster 
void GravitySystem::update(Iter *it)
{

    const Group *group = Ecs::get_group<Transform, MassComponent, GravityAttractor>(it->registry);

    const Transform *t_list     = Ecs::get_comp_array<Transform>(group, 0);
    const MassComponent *m_list = Ecs::get_comp_array<MassComponent>(group, 1);


    const Group *group_affected = Ecs::get_group<Transform, MassComponent, Velocity, GravityAffected>(it->registry);

    const Transform *t_list_a     = Ecs::get_comp_array<Transform>(group_affected, 0);



    for (I64 i = 0; i < group->size; ++i)
    {
        Entity e1 = group->entity_list[i];


        Transform t = t_list[i];
        MassComponent mass = m_list[i];

        for (I64 j = 0; j < group_affected->size; ++j)
        {
            Entity e2 = group_affected->entity_list[j];
            if (e1 == e2)
            {
                continue;
            }

            Transform t2 = t_list_a[j]; 

            Velocity *vel = Ecs::get_component<Velocity>(it->registry, e2);

            float center1_x = t.pos.x;
            float center1_y = t.pos.y;

            float center2_x = t2.pos.x;
            float center2_y = t2.pos.y;

            float center_dx = center1_x - center2_x;
            float center_dy = center1_y - center2_y;

            float distance2 = (center_dx) * (center_dx) + (center_dy) * (center_dy);
            float angle = atan2f((center_dy), (center_dx));

           
            float accl = G * mass.mass / (distance2 + FLT_MIN); // FLT_MIN to avoid div by zero 

            vel->v.x += cosf(angle) * accl * it->Ts;
            vel->v.y += sinf(angle) * accl * it->Ts;
        }
    }




}



void HealthSystem::on_kill(Iter *it)
{
    KillEvent *event = (KillEvent *)it->event;

    Ecs::destroy_entity(it->registry, event->e);
}


void HealthSystem::update(Iter *it)
{
    const Group *group = Ecs::get_group<HealthComponent>(it->registry);

    const HealthComponent *hc_list = Ecs::get_comp_array<HealthComponent>(group, 0);


    for (Usize i = 0; i < group->size; ++i)
    {

        Entity e = group->entity_list[i];
        HealthComponent hc = hc_list[i];

        if (hc.health < 0.0f)
        {
            KillEvent ke = {
                .e = e,
            };
            Ecs::push_event<KillEvent>(it->registry, &ke);
        }
        else
        {
            HealthComponent *hc_mut = Ecs::get_component<HealthComponent>(it->registry, e);
            hc_mut->health = hc.health + hc.health_regen * it->Ts;
        }
    }
}



void MovementSystem::update(Iter *iter)
{
    View<Velocity> *vel_view = Ecs::get_view<Velocity, Transform>(iter->registry);

    for(size_t i = 0; i < vel_view->size; ++i)
    {
        Entity e = vel_view->entity_list[i];
        Transform *transform = Ecs::get_component<Transform>(iter->registry, e);
        Velocity vel = vel_view->comparray[i];

        
        transform->pos.x += vel.v.x * iter->Ts;
        transform->pos.y += vel.v.y * iter->Ts;
    }
}


#include <math.h>


struct Timer
{
    float max_val;
    float time;
};




static float lerp(float current, float target, float step)
{
    return current + step * (target - current);
}



static Timer shoot_timer = {
    .max_val = 0.4f,
    .time = 0.0f,
};


const float rotation_speed = 1.0f;

void PlayerSystem::update(Iter *it)
{
    const Group *group = Ecs::get_group<Player>(it->registry);
    if (group->size < 1)
    {
        return;
    }

    Entity active_camera = Application::get_first_active_camera(it->registry);


    Entity player = group->entity_list[0]; 


    Transform *transform = Ecs::get_component<Transform>(it->registry, player);
    Velocity *vel = Ecs::get_component<Velocity>(it->registry, player);

    float vel_x_target;
    float vel_y_target;


    float speed = 5000.0f;

    vel_x_target = 0.0f;
    vel_y_target = 0.0f;

    {
        Vec2 vel_direction = {0.0f, 0.0f};
        
        if (Real::IsKeyPressed(VK_KEY_W))
        {
            vel_direction.y += -1.0f;
        }

        if (Real::IsKeyPressed(VK_KEY_S))
        {
            vel_direction.y += 1.0f;
        }

        if (Real::IsKeyPressed(VK_KEY_A))
        {
            vel_direction.x += -1.0f;
        }

        if (Real::IsKeyPressed(VK_KEY_D))
        {
            vel_direction.x += 1.0f;
        }

        if (vel_direction.x != 0.0f || vel_direction.y != 0.0f)
            Real::normalize(&vel_direction);
        vel_x_target = speed * vel_direction.x;
        vel_y_target = speed * vel_direction.y;
    }


    MousePos mpos = Real::getMousePos();


    Transform *t_camera = Ecs::get_component<Transform>(it->registry, active_camera);
    CameraComponent *cc_camera = Ecs::get_component<CameraComponent>(it->registry, active_camera);

    //TODO(Johan): fix mouse tracking
    /*{
        float world_mx = Real::screen_to_world_x(t_camera, cc_camera, mpos.x);
        float world_my = Real::screen_to_world_y(t_camera, cc_camera, mpos.y);

        float dx = world_mx - transform->pos.x;
        float dy = world_my - transform->pos.y;

        float angle = atan2f(dy, dx);
        transform->rot = {cosf(angle), sinf(angle)};
    }*/


    vel->v.x = lerp(vel->v.x, vel_x_target, it->Ts * 6);
    vel->v.y = lerp(vel->v.y, vel_y_target, it->Ts * 6);

    
    if (Real::IsMousePressed(mouseCodes::VK_MOUSE_BUTTON_LEFT))
    {
        shoot_timer.time += it->Ts;
        if (shoot_timer.time >= shoot_timer.max_val)
        {
            shoot_timer.time -= shoot_timer.max_val;
            BulletSpawnEvent bse = {
                .transform = {
                    .pos = transform->pos + transform->rot * 400.0f,
                    .rot = transform->rot,
                    .scale = {50.0f, 50.0f, 0.0f},
                },
                .mesh = Real::get_mesh("square_mesh"),
                .material = Real::get_material("ship_material"),
                .vel = transform->rot * speed,
                .damage = 5.0f,
            };
            Ecs::push_event<BulletSpawnEvent>(it->registry, &bse);           
        }
    }

    
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_T))
    {
        transform->pos.z += 1.0f;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_G))
    {
        transform->pos.z -= 1.0f;
    }


    if (Real::IsKeyPressed(KeyCodes::VK_KEY_I))
    {
        transform->rot.x += rotation_speed * it->Ts;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_K))
    {
        transform->rot.x -= rotation_speed * it->Ts;
    }


    if (Real::IsKeyPressed(KeyCodes::VK_KEY_U))
    {
        transform->rot.y -= rotation_speed * it->Ts;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_O))
    {
        transform->rot.y += rotation_speed * it->Ts;
    }


    if (Real::IsKeyPressed(KeyCodes::VK_KEY_J))
    {
        transform->rot.z -= rotation_speed * it->Ts;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_L))
    {
        transform->rot.z += rotation_speed * it->Ts;
    }



}




//#define PROFILE_FUNCTIONS
#include "../files/Time.hpp"

void RenderSystem::render(Iter *it)
{
    BEGIN_PROFILE_BLOCK();


    const Group *group = Ecs::get_group<Transform, MeshComponent, MaterialComponent>(it->registry);

    const Transform *transform_list    = Ecs::get_comp_array<Transform>(group, 0);
    const MeshComponent *mesh_list     = Ecs::get_comp_array<MeshComponent>(group, 1);
    const MaterialComponent *material_list = Ecs::get_comp_array<MaterialComponent>(group, 2);

    for (Usize i = 0; i < group->size; ++i)
    {
        Renderer::draw(&transform_list[i], &mesh_list[i], &material_list[i]);
    }
    
    END_PROFILE_BLOCK();
}


#include <math.h>

/**
 * @return float between 0.0f and 1.0f
 */
static float rand_float()
{
    return (float)rand() / (float)RAND_MAX;
}





static U8 wave = 0;

static float timer = 0.0f;






void SpawnerSystem::update(Iter *it)
{
    if (it->Ts > 0.2f) // stop lag from affecting spawning
    {
        return;
    }

    const Group *group = Ecs::get_group<Transform, SpriteComponent, Planet>(it->registry);

    if (group->size < 1)
    {
        return;
    }

    const Transform *t_list = Ecs::get_comp_array<Transform>(group, 0);
    const SpriteComponent *sc_list = Ecs::get_comp_array<SpriteComponent>(group, 1);

    const Transform planet_transform = t_list[0];


    float min_radius = ((float)sc_list[0].sprite->width / 2.0f) * t_list[0].scale.x;

    //printf("DEBUG: Timer = %.2f\n", timer);
    switch (wave)
    {
        case 0:
        {
            if (timer > 5 )
            {

                for (int i = 0; i < 100; ++i)
                {
                    float angle = 2 * 3.1415926f * rand_float();
                    float random_spawn_radius = (min_radius + 8000.0f) + rand_float() * 20000.0f;
    
                    AiSpawnEvent ase = {
                        .transform = {
                            .pos = {
                                cosf(angle) * random_spawn_radius + planet_transform.pos.x, 
                                sinf(angle) * random_spawn_radius + planet_transform.pos.y,
                                0.0f,
                            },
                            .rot = {1.0f, 0.0f, 0.0f},
                            .scale = {114.0f, 200.0f, 0.0f},
                        },
                        .mesh = Real::get_mesh("ship_mesh"),
                        .material = Real::get_material("ship_material"),
                        .vel = {0.0f, 0.0f, 0.0f},

                        .ai_type = AIType::Enemy,
                        .health = 500.0f,
                        .health_regen = 0.1f,
                    };
    
    
                    Ecs::push_event(it->registry, &ase);
                }
                wave += 1;
                timer = 0.0f;
            }
        } break;


        case 1:
        {



        } break;


        case 2:
        {
        } break;


        case 3:
        {
        } break;


        case 4:
        {
        } break;


        case 5:
        {
        } break;


        case 6:
        {
        } break;


        case 7:
        {
        } break;


        default:
        {
        } break;
    }


    timer += it->Ts;
}



