#include "asset.hpp"
#include "../datastructures/hashmap.hpp"
#include "../platform/platform.hpp"

#include "../Renderer/Shader.hpp"


#include <stdlib.h>

static HashMap<void *> s_path_map;
static HashMap<void *> s_name_map;

static engine_data *s_engine;


void Internal::init_asset(engine_data *engine) // TODO(Johan): maybe pass in arena here and not directly access the global memory
{
    HashMapN::init(&s_path_map);
    HashMapN::init(&s_name_map);
    ::s_engine = engine;

    Internal::init_textures();
}


void Internal::clean_asset()
{
    Internal::clean_textures();
}


static const char *slurp_file(const char *path, top_memory_arena *arena)
{
    FILE *file = fopen(path, "r");

    if (file == nullptr)
    {
        fprintf(stderr, "WARNING: failed to load file %s : %s\n", path, strerror(errno));
        return nullptr;
    }

    fseek(file, 0, SEEK_END);

    I64 file_length = ftell(file);

    rewind(file);

    char *slurped_file = Arena::top_alloc<char>(arena, file_length + 1);    

    memset(slurped_file, 0, file_length + 1);
    fread(slurped_file, 1, file_length, file);


    fclose(file);
    return slurped_file; 
}


enum class AssetType
{
    Mesh,
    Texture,
    VertSrc,
    FragSrc,
};


static U64 *check_if_path_hash_exists_and_get_hash(const char *path, AssetType type)
{
    char *buffer = Arena::top_alloc<char>(&g_memory.scratch_buffer, 1024);
    Platform::get_abs_path(path, buffer, 1024);

    U64 path_hash = HashMapN::hash_string(buffer);

    if (HashMapN::get_pointer(&s_path_map, path_hash) != nullptr)
    {
        const char *type_s;

        switch (type)
        {
            case AssetType::Mesh:
            {
                type_s = "Mesh";
            } break;
    
    
            case AssetType::Texture:
            {
                type_s = "Texture";
            } break;
    
    
            case AssetType::VertSrc:
            {
                type_s = "Vertex source";
            } break;
    
    
            case AssetType::FragSrc:
            {
                type_s = "Fragment source";
            } break;
    
    
            default:
            {
                assert(false, "unreachable");
                return nullptr;
            } break;
        }

        fprintf(stderr, "WARNING: tried to load %s that already exists or hash collision\n", type_s);
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return nullptr;
    }

    U64 *hash = Arena::top_alloc<U64>(&g_memory.scratch_buffer);

    *hash = path_hash;

    return hash;
}


static U64 *check_if_name_hash_already_exists_and_get_hash(const char *name)
{
    U64 name_hash = HashMapN::hash_string(name);

    if (HashMapN::get_pointer(&s_name_map, name_hash) != nullptr)
    {
        fprintf(stderr, "WARNING: tried to use \"%s\" which is already in use", name);
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return nullptr;
    }

    U64 *hash = Arena::top_alloc<U64>(&g_memory.scratch_buffer);

    *hash = name_hash;

    return hash;
}


void Real::load_mesh(const char *name, const char *path)
{
    U64 *path_hash = check_if_path_hash_exists_and_get_hash(path, AssetType::Mesh);
    U64 *name_hash = check_if_name_hash_already_exists_and_get_hash(name);

    if (path_hash == nullptr || name_hash == nullptr)
    {
        return;
    }


    Mesh *mesh = Arena::top_alloc<Mesh>(&g_memory.asset_buffer);


    const char *mesh_source = slurp_file(path, &g_memory.scratch_buffer);

    MeshN::init(mesh, mesh_source);

    HashMapN::set(&s_path_map, *path_hash, (void *)mesh);
    HashMapN::set(&s_name_map, *name_hash, (void *)mesh);

    fprintf(stderr, "NOTE: loaded mesh from %s\n", path);

    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::load_texture(const char *name, const char *path)
{
    assert(false, "not implemented");
    return;
}


void Real::load_vertex_shader_src(const char *name, const char *path)
{
    U64 *path_hash = check_if_path_hash_exists_and_get_hash(path, AssetType::VertSrc);
    U64 *name_hash = check_if_name_hash_already_exists_and_get_hash(name);
    if (path_hash == nullptr || name_hash == nullptr)
    {
        return;
    }

    const char *src = slurp_file(path, &g_memory.asset_buffer);

    HashMapN::set(&s_path_map, *path_hash, (void *)src);
    HashMapN::set(&s_name_map, *name_hash, (void *)src);
    fprintf(stderr, "NOTE: loaded vertex source from %s\n", path);
}


void Real::load_fragment_shader_src(const char *name, const char *path)
{
    U64 *path_hash = check_if_path_hash_exists_and_get_hash(path, AssetType::FragSrc);
    U64 *name_hash = check_if_name_hash_already_exists_and_get_hash(name);
    if (path_hash == nullptr || name_hash == nullptr)
    {
        return;
    }

    const char *src = slurp_file(path, &g_memory.asset_buffer);

    HashMapN::set(&s_path_map, *path_hash, (void *)src);
    HashMapN::set(&s_name_map, *name_hash, (void *)src);
    fprintf(stderr, "NOTE: loaded fragment source from %s\n", path);
}


void Real::load_shader(const char *name, const char *vert_src, const char *frag_src)
{
    U64 *name_hash = check_if_name_hash_already_exists_and_get_hash(name);

    if (name_hash == nullptr)
    {
        return;
    }

    Shader *shader = Arena::top_alloc<Shader>(&g_memory.asset_buffer);

    Real::init_shader(shader, vert_src, frag_src);

    HashMapN::set(&s_name_map, *name_hash, (void *)shader);
}


void Real::init_sprite(const char *name, U32 x, U32 y, U32 w, U32 h, Texture *texture)
{
    if (w > texture->width)
    {
        fprintf(stderr, "WARNING: sprite width cannot be larger than texture width");
        return;
    }

    if (h > texture->height)
    {
        fprintf(stderr, "WARNING: sprite height cannot be larger than texture height ");
        return;
    }

    U64 *name_hash = check_if_name_hash_already_exists_and_get_hash(name);

    if (name_hash == nullptr)
    {
        return;
    }



    Sprite *sprite = Arena::top_alloc<Sprite>(&g_memory.asset_buffer);

    *sprite = {
        .x       = x,
        .y       = y,
        .width   = w,
        .height  = h,
        .texture = texture,
    };

    HashMapN::set(&s_name_map, *name_hash, (void *)sprite);
}


static void *get_item(const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    void *pointer = HashMapN::get_value(&s_name_map, hash);

    return pointer;    
}


Mesh *Real::get_mesh(const char *name)
{
    Mesh *mesh = (Mesh *)get_item(name);

    if (mesh == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Mesh not found\n", name);
    }

    return mesh;
}


Texture *Real::get_texture(const char *name)
{
    Texture *texture = (Texture *)get_item(name);

    if (texture == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Texture not found\n", name);
    }

    return texture;
}


Sprite *Real::get_sprite(const char *name)
{
    Sprite *sprite = (Sprite *)get_item(name);

    if (sprite == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Sprite not found\n", name);
    }

    return sprite;
}


const char *Real::get_vertex_src(const char *name)
{
    const char *vert_src = (const char *)get_item(name);

    if (vert_src == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Vertex source not found\n", name);
    }

    return vert_src;    
}


const char *Real::get_fragment_src(const char *name)
{
    const char *frag_src = (const char *)get_item(name);

    if (frag_src == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Fragment source not found\n", name);
    }

    return frag_src;    
}


Shader *Real::get_shader(const char *name)
{
    Shader *shader = (Shader *)get_item(name);

    if (shader == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Shader not found\n", name);
    }

    return shader;
}


U32 Real::get_sprite_width(Sprite *sprite)
{
    return sprite->width;
}


U32 Real::get_sprite_height(Sprite *sprite)
{
    return sprite->height;
}

