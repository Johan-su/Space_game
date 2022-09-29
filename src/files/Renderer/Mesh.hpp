#pragma once


#include "../int.hpp"
#include "../math/math_types.hpp"

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"



#define MAX_TRIANGLES 128
#define MAX_VERTICIES MAX_TRIANGLES * 3
#define MAX_INDICIES MAX_TRIANGLES * 3


#define VERTEX_NULL -2.0f
#define INDEX_NULL -1


struct Vertex
{
    Vec3 pos;
    Vec2 tex_coords;
};


struct MeshVertexBuffer
{
    Usize vertex_count;
    Vertex verticies[MAX_VERTICIES];
};


struct MeshIndexBuffer
{
    Usize index_count;
    I32 indicies[MAX_INDICIES];
};


struct MeshData
{
    MeshVertexBuffer vertex_buffer;
    MeshIndexBuffer index_buffer;
};


struct Mesh
{
    VertexArray va;
    IndexBuffer ib; 
};




namespace MeshN
{
    void init(Mesh *mesh, const char *mesh_src);
} // namespace MeshN
