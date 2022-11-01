#pragma once

#include "../int.hpp"

class Vec2
{
public:
    union {float x, r, u;};
    union {float y, g, v;};


    Vec2 operator+(Vec2 v2f) { return Vec2 {this->x + v2f.x, this->y + v2f.y}; }
    Vec2 operator-(Vec2 v2f) { return Vec2 {this->x - v2f.x, this->y - v2f.y}; }


    Vec2 operator+(float s)  { return Vec2 {this->x + s, this->y + s}; }
    Vec2 operator-(float s)  { return Vec2 {this->x - s, this->y - s}; }
    Vec2 operator*(float s)  { return Vec2 {this->x * s, this->y * s}; }
    Vec2 operator/(float s)  { return Vec2 {this->x / s, this->y / s}; }

    void operator+=(float s) { *this = *this + s; }
    void operator-=(float s) { *this = *this - s; }
    void operator*=(float s) { *this = *this * s; }
    void operator/=(float s) { *this = *this / s; }

};


class Vec3
{
public:
    union {float x, r;};
    union {float y, g;};
    union {float z, b;};

    Vec2 xy() { return Vec2 {this->x, this->y}; }

    Vec3 operator+(Vec3 v) { return Vec3 {this->x + v.x, this->y + v.y, this->z + v.z}; }
    Vec3 operator-(Vec3 v) { return Vec3 {this->x - v.x, this->y - v.y, this->z - v.z}; }


    Vec3 operator+(float s)  { return Vec3 {this->x + s, this->y + s, this->z + s}; }
    Vec3 operator-(float s)  { return Vec3 {this->x - s, this->y - s, this->z - s}; }
    Vec3 operator*(float s)  { return Vec3 {this->x * s, this->y * s, this->z * s}; }
    Vec3 operator/(float s)  { return Vec3 {this->x / s, this->y / s, this->z / s}; }

    void operator+=(float s) { *this = *this + s; }
    void operator-=(float s) { *this = *this - s; }
    void operator*=(float s) { *this = *this * s; }
    void operator/=(float s) { *this = *this / s; }
   
};


class Vec4
{
public:
    union
    {
        float array[4];
        struct
        {
            union {float x, r;};
            union {float y, g;};
            union {float z, b;};
            union {float w, a;};
        };
    };

    float &operator[](int index) { return this->array[index]; };


    Vec3 xyz() { return Vec3 {this->x, this->y, this->z}; }

    Vec4 operator+(Vec4 v4f) { return Vec4 {this->x + v4f.x, this->y + v4f.y, this->z + v4f.z, this->w + v4f.w}; }
    Vec4 operator-(Vec4 v4f) { return Vec4 {this->x - v4f.x, this->y - v4f.y, this->z - v4f.z, this->w - v4f.w}; }


    Vec4 operator+(float s)  { return Vec4 {this->x + s, this->y + s, this->z + s, this->w + s}; }
    Vec4 operator-(float s)  { return Vec4 {this->x - s, this->y - s, this->z - s, this->w - s}; }
    Vec4 operator*(float s)  { return Vec4 {this->x * s, this->y * s, this->z * s, this->w * s}; }
    Vec4 operator/(float s)  { return Vec4 {this->x / s, this->y / s, this->z / s, this->w / s}; }

    void operator+=(float s) { *this = *this + s; }
    void operator-=(float s) { *this = *this - s; }
    void operator*=(float s) { *this = *this * s; }
    void operator/=(float s) { *this = *this / s; }

};



class Mat2
{
public:
    union {Vec2 x1, i;};
    union {Vec2 x2, j;};

    Vec2 operator*(Vec2 v2f) { return (x1 * v2f.x) + (x2 * v2f.y); }

    Mat2 operator*(Mat2 mat2) { return Mat2 { *this * mat2.x1, *this * mat2.x2, }; } 
};


class Mat3
{
public:
    union {Vec3 x1, i;};
    union {Vec3 x2, j;};
    union {Vec3 x3, k;};

    Vec3 operator*(Vec3 v3f) { return (x1 * v3f.x) + (x2 * v3f.y) + (x3 * v3f.z); }

    Mat3 operator*(Mat3 mat3) { return Mat3 { *this * mat3.x1, *this * mat3.x2, *this * mat3.x3, }; } 
};


class Mat4
{
public:
    union
    {
        Vec4 array[4];
        struct
        {
            union {Vec4 x1, i;};
            union {Vec4 x2, j;};
            union {Vec4 x3, k;};
            union {Vec4 x4, l;};
        };
    };

    Vec4 &operator[](int index) { return this->array[index]; };

    Mat4 operator*(float s) { return Mat4 {this->x1 * s, this->x2 * s, this->x3 * s, this->x4 * s}; };
    Vec4 operator*(Vec4 v4f) { return (x1 * v4f.x) + (x2 * v4f.y) + (x3 * v4f.z) + (x4 * v4f.w); }

    Mat4 operator*(Mat4 mat4) { return Mat4 { *this * mat4.x1, *this * mat4.x2, *this * mat4.x3, *this * mat4.x4, }; }
};



typedef float BiVec2;
typedef Vec3 BiVec3;
// https://marctenbosch.com/quaternions/
// https://marctenbosch.com/quaternions/code.htm
// https://www.youtube.com/watch?v=PNlgMPzj-7Q&list=PLpzmRsG7u_gqaTo_vEseQ7U8KFvtiJY4K


class Rot2
{
public:
    float s;
    BiVec2 bivec;
};


class Rot3
{
public:
    float s;
    BiVec3 bivec;
};


namespace Real
{

    float dot(Vec2 *v1, Vec2 *v2);
    float dot(Vec3 *v1, Vec3 *v2);
    float dot(Vec4 *v1, Vec4 *v2); 

    // returns the area (as a bivector) bounded by the vectors.
    BiVec2 wedge(Vec2 *v1, Vec2 *v2);
    BiVec3 wedge(Vec3 *v1, Vec3 *v2);

    Rot2 geoprod(Vec2 *v1, Vec2 *v2);
    Rot3 geoprod(Vec3 *v1, Vec3 *v2);




    void normalize(Vec2 *v);
    void normalize(Vec3 *v);
    void normalize(Vec4 *v);

    void normalize(Rot2 *r);
    void normalize(Rot3 *r);

    Vec3 cross(Vec3 *v1, Vec3 *v2);


    Rot3 from_to(Vec3 *v_from, Vec3 *v_to);






    Mat4 transpose(Mat4 *matrix);
    Mat4 gauss_eliminate(Mat4 *matrix);
    float determinant(Mat4 *matrix);
    Mat4 inverse(Mat4 *matrix);

    Mat4 orthographic(float left, float right, float top, float bottom, float znear, float zfar);
} // namespace Real

