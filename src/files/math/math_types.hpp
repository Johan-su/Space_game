#pragma once

#include "../int.hpp"

class Vector2f
{
public:


    union {float x, r, u;};
    union {float y, g, v;};


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
    union {float x, r;};
    union {float y, g;};
    union {float z, b;};

    Vector2f xy() { return Vector2f {this->x, this->y}; }

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
    union {float x, r;};
    union {float y, g;};
    union {float z, b;};
    union {float w, a;};


    Vector3f xyz() { return Vector3f {this->x, this->y, this->z}; }

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






class Mat2
{
public:
    union {Vector2f x1, i;};
    union {Vector2f x2, j;};

    Vector2f operator*(Vector2f v2f) { return (x1 * v2f.x) + (x2 * v2f.y); }

    Mat2 operator*(Mat2 mat2) { return Mat2 { *this * mat2.x1, *this * mat2.x2, }; } 
};


class Mat3
{
public:
    union {Vector3f x1, i;};
    union {Vector3f x2, j;};
    union {Vector3f x3, k;};

    Vector3f operator*(Vector3f v3f) { return (x1 * v3f.x) + (x2 * v3f.y) + (x3 * v3f.z); }

    Mat3 operator*(Mat3 mat3) { return Mat3 { *this * mat3.x1, *this * mat3.x2, *this * mat3.x3, }; } 
};



class Mat4
{
public:
    union {Vector4f x1, i;};
    union {Vector4f x2, j;};
    union {Vector4f x3, k;};
    union {Vector4f x4, l;};


    Vector4f operator*(Vector4f v4f) { return (x1 * v4f.x) + (x2 * v4f.y) + (x3 * v4f.z) + (x4 * v4f.w); }

    Mat4 operator*(Mat4 mat4) { return Mat4 { *this * mat4.x1, *this * mat4.x2, *this * mat4.x3, *this * mat4.x4, }; } 
};


namespace Real
{
   Mat4 orthographic(float left, float right, float top, float bottom, float znear, float zfar); 
} // namespace Real

