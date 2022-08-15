#pragma once

#include "../int.hpp"

#include "../math/math_types.hpp"

#define MAX_TRIANGLES 128
#define MAX_VERTICIES MAX_TRIANGLES * 3
#define MAX_INDICIES MAX_TRIANGLES * 3


#define VERTEX_NULL -2.0f
#define INDEX_NULL -1


struct Vertex
{
    Vector3f pos;
    Vector2f tex_coords;
};

struct VertexBuffer
{
    Usize vertex_count;
    Vertex verticies[MAX_VERTICIES];
};



struct IndexBuffer
{
    Usize index_count;
    I32 indicies[MAX_INDICIES];
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







