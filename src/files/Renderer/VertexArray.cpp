#include "VertexArray.hpp"


#include "../core/loadgl/load_gl.hpp"

void Real::init_vArray(VertexArray *va)
{
    glGenVertexArrays(1, &va->id);
}   


void Real::clean_vArray(VertexArray *va)
{
    glDeleteVertexArrays(1, &va->id);
}   


void Real::bind(VertexArray *va)
{
    glBindVertexArray(va->id);
}   


void Real::unbind(VertexArray *va)
{
    glBindVertexArray(0);
}   

