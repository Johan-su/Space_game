#pragma once

#include "../int.hpp"

#define MAX_TRIANGLES 128
#define MAX_VERTICIES MAX_TRIANGLES * 3
#define MAX_INDICIES MAX_TRIANGLES


#define VERTEX_NULL -2.0f
#define INDEX_NULL -1


struct VertexBuffer
{
    float x[MAX_VERTICIES];
    float y[MAX_VERTICIES];
};



struct IndexBuffer
{
    I32 v1[MAX_INDICIES]; 
    I32 v2[MAX_INDICIES]; 
    I32 v3[MAX_INDICIES]; 
};




struct Mesh
{
    VertexBuffer vertex_buffer;
    IndexBuffer index_buffer;
};





namespace MeshN
{
    void init(Mesh *mesh, const char *mesh_src);
} // namespace MeshN







