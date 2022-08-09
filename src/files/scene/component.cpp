#include "component.hpp"
#include <math.h>




float Vector2f::magnitude()
{
    return sqrtf(this->x * this->x + this->y * this->y);
}




void Vector2f::normalize()
{
    float mag = this->magnitude();

    if (mag < 0.9f)
        return;

    this->x = this->x / mag;
    this->y = this->y / mag;

}