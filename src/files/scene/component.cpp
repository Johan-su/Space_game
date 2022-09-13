#include "component.hpp"



#include <math.h>



Mat4 Real::transform_to_mat4(const Transform *transform)
{
    Mat4 translation = {
        .x1 = {1.0f, 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, 1.0f, 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, 1.0f, 0.0f},
        .x4 = {transform->pos.x, transform->pos.y, 0.0f, 1.0f},
    };


    float xy_angle = transform->rot.z;

    float v1_xy = cosf(xy_angle);
    float v2_xy = sinf(xy_angle);


    Mat4 zrotation = {
        .x1 = {v1_xy, v2_xy, 0.0f, 0.0f},
        .x2 = {-v2_xy, v1_xy, 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, 1.0f, 0.0f},
        .x4 = {0.0f, 0.0f, 0.0f, 1.0f},
    };


    float zx_angle = transform->rot.y;

    float v1_zx = cosf(zx_angle);    
    float v2_zx = sinf(zx_angle);    

    Mat4 yrotation = {
        .x1 = {v1_zx, 0.0f, -v2_zx, 0.0f},
        .x2 = {0.0f, 1.0f, 0.0f, 0.0f},
        .x3 = {v2_zx, 0.0f, v1_zx, 0.0f},
        .x4 = {0.0f, 0.0f, 0.0f, 1.0f},
    };


    float yz_angle = transform->rot.x;

    float v1_yz = cosf(yz_angle);
    float v2_yz = sinf(yz_angle);


    Mat4 xrotation = {
        .x1 = {1.0f, 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, v1_yz, v2_yz, 0.0f},
        .x3 = {0.0f, -v2_yz, v1_yz, 0.0f},
        .x4 = {0.0f, 0.0f, 0.0f, 1.0f},
    };




    Mat4 rotation = xrotation * yrotation * zrotation;







    Mat4 scaling = {
        .x1 = {transform->scale.x, 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, transform->scale.y, 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, transform->scale.z, 0.0f},
        .x4 = {0.0f, 0.0f, 0.0f, 1.0f},
    };


    Mat4 result = translation * rotation * scaling; 



    return result; 

}