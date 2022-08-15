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


class Vector3f
{
public:
    float x;
    float y;
    float z;

    Vector3f operator+(Vector3f v3f) { return Vector3f {this->x + v3f.x, this->y + v3f.y, this->z + v3f.z}; }
    Vector3f operator-(Vector3f v3f) { return Vector3f {this->x - v3f.x, this->y - v3f.y, this->z - v3f.z}; }


    Vector3f operator+(float scalar)  { return Vector3f {this->x + scalar, this->y + scalar, this->z + scalar}; }
    Vector3f operator-(float scalar)  { return Vector3f {this->x - scalar, this->y - scalar, this->z - scalar}; }
    Vector3f operator*(float scalar)  { return Vector3f {this->x * scalar, this->y * scalar, this->z * scalar}; }
    Vector3f operator/(float scalar)  { return Vector3f {this->x / scalar, this->y / scalar, this->z / scalar}; }

    void operator+=(float scalar) { *this = *this + scalar; }
    void operator-=(float scalar) { *this = *this - scalar; }
    void operator*=(float scalar) { *this = *this * scalar; }
    void operator/=(float scalar) { *this = *this / scalar; }


    float magnitude();
    void normalize();
    float dot(Vector3f v3f);
};


class Vector4f
{
public:
    float x;
    float y;
    float z;
    float w;

    Vector4f operator+(Vector4f v4f) { return Vector4f {this->x + v4f.x, this->y + v4f.y, this->z + v4f.z, this->w + v4f.w}; }
    Vector4f operator-(Vector4f v4f) { return Vector4f {this->x - v4f.x, this->y - v4f.y, this->z - v4f.z, this->w - v4f.w}; }


    Vector4f operator+(float scalar)  { return Vector4f {this->x + scalar, this->y + scalar, this->z + scalar, this->w + scalar}; }
    Vector4f operator-(float scalar)  { return Vector4f {this->x - scalar, this->y - scalar, this->z - scalar, this->w - scalar}; }
    Vector4f operator*(float scalar)  { return Vector4f {this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar}; }
    Vector4f operator/(float scalar)  { return Vector4f {this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar}; }

    void operator+=(float scalar) { *this = *this + scalar; }
    void operator-=(float scalar) { *this = *this - scalar; }
    void operator*=(float scalar) { *this = *this * scalar; }
    void operator/=(float scalar) { *this = *this / scalar; }


    float magnitude();
    void normalize();
    float dot(Vector4f v4f);
};