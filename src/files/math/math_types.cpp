#include "math_types.hpp"

#include <math.h>




float Vector2f::magnitude()
{
    return sqrtf(this->x * this->x + this->y * this->y);
}


void Vector2f::normalize()
{
    float mag = this->magnitude();

    if (mag < 0.0001f) // must be a zero vector
        return;

    this->x = this->x / mag;
    this->y = this->y / mag;

}


float Vector2f::dot(Vector2f other_v2f)
{
    return this->x * other_v2f.x + this->y * other_v2f.y;
}












float Vector3f::magnitude()
{
    return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}


void Vector3f::normalize()
{
    float mag = this->magnitude();

    if (mag < 0.0001f) // must be a zero vector
        return;

    this->x = this->x / mag;
    this->y = this->y / mag;
    this->z = this->z / mag;

}


float Vector3f::dot(Vector3f other_v3f)
{
    return this->x * other_v3f.x + this->y * other_v3f.y + this->z * other_v3f.z;
}










float Vector4f::magnitude()
{
    return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
}


void Vector4f::normalize()
{
    float mag = this->magnitude();

    if (mag < 0.0001f) // must be a zero vector
        return;

    this->x = this->x / mag;
    this->y = this->y / mag;
    this->z = this->z / mag;
    this->w = this->w / mag;

}


float Vector4f::dot(Vector4f other_v4f)
{
    return this->x * other_v4f.x + this->y * other_v4f.y + this->z * other_v4f.z + this->w * other_v4f.w;
}



Mat4 Real::orthographic(float left, float right, float top, float bottom, float znear, float zfar)
{
    return Mat4 {
        .x1 = {2.0f / (right - left), 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, 2.0f / (top - bottom), 0.0f, 0.0f}, // -2.0f because opengl defines y up as positive
        .x3 = {0.0f, 0.0f, -2.0f / (zfar - znear)},
        .x4 = {
            -(right + left) / (right - left), 
            -(top + bottom) / (top - bottom), // + was (-) because opengl defines y as up
            -(zfar + znear) / (zfar - znear), 
            1.0f
        },
    };
}