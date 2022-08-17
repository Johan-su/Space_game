#pragma once

#include "../int.hpp"

struct Shader
{
    U32 id;
};



namespace Real
{
   void init_shader(Shader *shader, const char *vert_src, const char *frag_src);

   void bind(Shader *shader);
   void unbind(Shader *shader);
} // namespace Real


