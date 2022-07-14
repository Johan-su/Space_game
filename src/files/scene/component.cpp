#include "component.hpp"





float Vector2::magnitude()
{
    return sqrtf(this->x * this->x + this->y * this->y);
}




void Vector2::normalize()
{
    float mag = this->magnitude();

    this->x = this->x / mag;
    this->y = this->y / mag;

}