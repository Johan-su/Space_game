#include "SpawnerSystem.hpp"
#include "../Components_Events.hpp"

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
                        .pos = {
                            cosf(angle) * random_spawn_radius + planet_transform.pos.x, 
                            sinf(angle) * random_spawn_radius + planet_transform.pos.y,
                        },
                        .scale = 1.0f,
                        .ship_sprite = Real::get_sprite("ship1_sprite"),
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