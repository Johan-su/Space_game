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
