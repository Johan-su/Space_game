#pragma once

#include "../int.hpp"

class Vector2f
{
public:
    float x;
    float y;

    Vector2f operator+(Vector2f v2f) { return Vector2f {this->x + v2f.x, this->y + v2f.y}; }
    Vector2f operator-(Vector2f v2f) { return Vector2f {this->x - v2f.x, this->y - v2f.y}; }


    Vector2f operator+(float scalar)  { return Vector2f {this->x + scalar, this->y + scalar}; }
    Vector2f operator-(float scalar)  { return Vector2f {this->x - scalar, this->y - scalar}; }
    Vector2f operator*(float scalar)  { return Vector2f {this->x * scalar, this->y * scalar}; }
    Vector2f operator/(float scalar)  { return Vector2f {this->x / scalar, this->y / scalar}; }

    void operator+=(float scalar) { *this = *this + scalar; }
    void operator-=(float scalar) { *this = *this - scalar; }
    void operator*=(float scalar) { *this = *this * scalar; }
    void operator/=(float scalar) { *this = *this / scalar; }


    float magnitude();
    void normalize();
    float dot(Vector2f v2f);
};
