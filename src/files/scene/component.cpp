#include "component.hpp"






Mat4 Real::transform_to_mat4(const Transform *transform)
{
    Mat4 translation = {
        .x1 = {1.0f, 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, 1.0f, 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, 1.0f, 0.0f},
        .x4 = {transform->pos.x, transform->pos.y, 0.0f, 1.0f},
    };


    Mat4 rotation = {
        .x1 = {transform->rot.x, transform->rot.y, 0.0f, 0.0f},
        .x2 = {-transform->rot.y, transform->rot.x, 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, 1.0f, 0.0f},
        .x4 = {0.0f, 0.0f, 0.0f, 1.0f},
    };


    Mat4 scaling = {
        .x1 = {transform->scale.x, 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, transform->scale.y, 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, 1.0f, 0.0f},
        .x4 = {0.0f, 0.0f, 0.0f, 1.0f},
    };


    Mat4 result = translation * rotation * scaling; 



    return result; 
}