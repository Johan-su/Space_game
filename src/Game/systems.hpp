#pragma once

#include "Game.hpp"

namespace AIControllerSystem
{
    void update(Iter *iter);
} // namespace AIControllerSystem



namespace AngleSystem
{
    void update(Iter *iter);

} // namespace AngleSystem


namespace CameraController
{
    void update(Iter *iter);
} // namespace CameraController


namespace CollisionSystem
{
    void update(Iter *iter);
    
} // namespace CollisionSystem


namespace DamageSystem
{
   void onCollision(Iter *it); 
} // namespace DamageSystem


#include "Components_Events.hpp"

namespace EntityCreationSystem
{
    
    void create_player(Iter *it);
    void create_bullet (Iter *it);
    void create_ai(Iter *it);
    void create_planet(Iter *it);
} // namespace EntityCreationSystem


namespace FiringSystem
{
   void update(Iter *it);
} // namespace FiringSystem


namespace GravitySystem
{
    void update(Iter *iter);

} // namespace GravitySystem


namespace HealthSystem
{
    void on_kill(Iter *it);
    void update(Iter *it);
} // namespace HealthSystem


namespace MovementSystem
{
    void update(Iter *iter);

}


namespace PlayerSystem
{
    void update(Iter *iter);

} // namespace PlayerSystem


namespace RenderSystem
{
    void render(Iter *it);
}


namespace SpawnerSystem
{
   void update(Iter *it); 
} // namespace TimerSystem
