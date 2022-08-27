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







Quaternion Real::quat_from_euler_angles(Vector3f angles)
{

}


Vector3f Real::euler_angles_from_quat(Quaternion quat)
{

}

        
Mat4 Real::transpose(Mat4 *matrix)
{
    Mat4 t_matrix = {};

    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            t_matrix.array[j].array[i] = matrix->array[i].array[j];
        }
    }
    return t_matrix;
}


Mat4 Real::gauss_eliminate(Mat4 *matrix)
{
    Mat4 t_matrix = transpose(matrix);

    for (int i = 0; i < 4; ++i)
    {
        if (t_matrix[i][i] == 0.0f)
        {
            return Mat4 {};
        }

        for (int j = i + 1; j < 4; ++j)
        {
            float ratio = (t_matrix[j][i] / t_matrix[i][i]);
            
            for (int k = i; k < 4; ++k)
            {
                t_matrix[j][k] -= ratio * t_matrix[i][k];
            }
        }
    }
    return t_matrix;
}


float Real::determinant(Mat4 *matrix)
{
    Mat4 eliminated_m = gauss_eliminate(matrix);

    float determinant = 1.0f;

    for (int i = 0; i < 4; ++i)
    {
        determinant *= eliminated_m[i][i];
    }

    return determinant;
}


Mat4 Real::inverse(Mat4 *matrix) 
{
    float det = determinant(matrix);

    
    
    Mat4 m = *matrix;

    // values come from https://semath.info/src/inverse-cofactor-ex4.html
    float i_11 =  m[1][1] * m[2][2] * m[3][3] +
                  m[1][2] * m[2][3] * m[3][1] +
                  m[1][3] * m[2][1] * m[3][2] -
                  m[1][3] * m[2][2] * m[3][1] -
                  m[1][2] * m[2][1] * m[3][3] -
                  m[1][1] * m[2][3] * m[3][2];

    float i_12 = -m[0][1] * m[2][2] * m[3][3] -
                  m[0][2] * m[2][3] * m[3][1] -
                  m[0][3] * m[2][1] * m[3][2] +
                  m[0][3] * m[2][2] * m[3][1] +
                  m[0][2] * m[2][1] * m[3][3] +
                  m[0][1] * m[2][3] * m[3][2];

    float i_13 =  m[0][1] * m[1][2] * m[3][3] +
                  m[0][2] * m[1][3] * m[3][1] +
                  m[0][3] * m[1][1] * m[3][2] -
                  m[0][3] * m[1][2] * m[3][1] -
                  m[0][2] * m[1][1] * m[3][3] -
                  m[0][1] * m[1][3] * m[3][2];

    float i_14 = -m[0][1] * m[1][2] * m[2][3] -
                  m[0][2] * m[1][3] * m[2][1] -
                  m[0][3] * m[1][1] * m[2][2] +
                  m[0][3] * m[1][2] * m[2][1] +
                  m[0][2] * m[1][1] * m[2][3] + 
                  m[0][1] + m[1][3] * m[2][2];




    float i_21 = -m[1][0] * m[2][2] * m[3][3] -
                  m[1][2] * m[2][3] * m[3][0] -
                  m[1][3] * m[2][0] * m[3][2] +
                  m[1][3] * m[2][2] * m[3][0] +
                  m[1][2] * m[2][0] * m[3][3] +
                  m[1][0] * m[2][3] * m[3][2];

    float i_22 =  m[0][0] * m[2][2] * m[3][3] +
                  m[0][2] * m[2][3] * m[3][0] +
                  m[0][3] * m[2][0] * m[3][2] -
                  m[0][3] * m[2][2] * m[3][0] -
                  m[0][2] * m[2][0] * m[3][3] -
                  m[0][0] * m[2][3] * m[3][2];

    float i_23 = -m[0][0] * m[1][2] * m[3][3] -
                  m[0][2] * m[1][3] * m[3][0] -
                  m[0][3] * m[1][0] * m[3][2] +
                  m[0][3] * m[1][2] * m[3][0] +
                  m[0][2] * m[1][0] * m[3][3] +
                  m[0][0] * m[1][3] * m[3][2];

    float i_24 =  m[0][0] * m[1][2] * m[2][3] +
                  m[0][2] * m[1][3] * m[2][0] +
                  m[0][3] * m[1][0] * m[2][2] -
                  m[0][3] * m[1][2] * m[2][0] -
                  m[0][2] * m[1][0] * m[2][3] -
                  m[0][0] * m[1][3] * m[2][2];




    float i_31 =  m[1][0] * m[2][1] * m[3][3] +
                  m[1][1] * m[2][3] * m[3][0] +
                  m[1][3] * m[2][0] * m[3][1] -
                  m[1][3] * m[2][1] * m[3][0] -
                  m[1][1] * m[2][0] * m[3][3] -
                  m[1][0] * m[2][3] * m[3][1];

    float i_32 = -m[0][0] * m[2][1] * m[3][3] -
                  m[0][1] * m[2][3] * m[3][0] -
                  m[0][3] * m[2][0] * m[3][1] +
                  m[0][3] * m[2][1] * m[3][0] +
                  m[0][1] * m[2][0] * m[3][3] +
                  m[0][0] * m[2][3] * m[3][1];

    float i_33 =  m[0][0] * m[1][1] * m[3][3] +
                  m[0][1] * m[1][3] * m[3][0] +
                  m[0][3] * m[1][0] * m[3][1] -
                  m[0][3] * m[1][1] * m[3][0] -
                  m[0][1] * m[1][0] * m[3][3] -
                  m[0][0] * m[1][3] * m[3][1];

    float i_34 = -m[0][0] * m[1][1] * m[2][3] -
                  m[0][1] * m[1][3] * m[2][0] -
                  m[0][3] * m[1][0] * m[2][1] +
                  m[0][3] * m[1][1] * m[2][0] +
                  m[0][1] * m[1][0] * m[2][3] +
                  m[0][0] * m[1][3] * m[2][1];




    float i_41 = -m[1][0] * m[2][1] * m[3][2] -
                  m[1][1] * m[2][2] * m[3][0] -
                  m[1][2] * m[2][0] * m[3][1] +
                  m[1][2] * m[2][1] * m[3][0] +
                  m[1][1] * m[2][0] * m[3][2] +
                  m[1][0] * m[2][2] * m[3][1];

    float i_42 =  m[0][0] * m[2][1] * m[3][2] +
                  m[0][1] * m[2][2] * m[3][0] +
                  m[0][2] * m[2][0] * m[3][1] -
                  m[0][2] * m[2][1] * m[3][0] -
                  m[0][1] * m[2][0] * m[3][2] -
                  m[0][0] * m[2][2] * m[3][1];

    float i_43 = -m[0][0] * m[1][1] * m[3][2] -
                  m[0][1] * m[1][2] * m[3][0] -
                  m[0][2] * m[1][0] * m[3][1] +
                  m[0][2] * m[1][1] * m[3][0] +
                  m[0][1] * m[1][0] * m[3][2] +
                  m[0][0] * m[1][2] * m[3][1];

    float i_44 =  m[0][0] * m[1][1] * m[2][2] + 
                  m[0][1] * m[1][2] * m[2][0] +
                  m[0][2] * m[1][0] * m[2][1] -
                  m[0][2] * m[1][1] * m[2][0] - 
                  m[0][1] * m[1][0] * m[2][2] -
                  m[0][0] * m[1][2] * m[2][1];



    Mat4 ad = {
        .x1 = {i_11, i_12, i_13, i_14},
        .x2 = {i_21, i_22, i_23, i_24},
        .x3 = {i_31, i_32, i_33, i_34},
        .x4 = {i_41, i_42, i_43, i_44},
    };

    float one_over_det = 1.0f / det;

    Mat4 result = ad * one_over_det;

    return result;
}


Mat4 Real::orthographic(float left, float right, float top, float bottom, float znear, float zfar)
{
    return Mat4 {
        .x1 = {2.0f / (right - left), 0.0f, 0.0f, 0.0f},
        .x2 = {0.0f, 2.0f / (top - bottom), 0.0f, 0.0f},
        .x3 = {0.0f, 0.0f, -2.0f / (zfar - znear)},
        .x4 = {
            -(right + left) / (right - left), 
            -(top + bottom) / (top - bottom),
            -(zfar + znear) / (zfar - znear), 
            1.0f
        },
    };
}