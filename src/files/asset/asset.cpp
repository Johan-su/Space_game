#include "asset.hpp"
#include "../datastructures/hashmap.hpp"
#include "../platform/platform.hpp"

#include "../Renderer/Shader.hpp"


#include <stdlib.h>

struct AssetData
{
    HashMap<void *> path_map;
    HashMap<void *> name_map;
};


static AssetData s_mesh_map;
static AssetData s_texture_map;
static AssetData s_string_map;
static AssetData s_shader_map;
static AssetData s_sprite_map;
static AssetData s_material_map;


static engine_data *s_engine;


void Internal::init_asset(engine_data *engine) // TODO(Johan): maybe pass in arena here and not directly access the global memory
{
    HashMapN::init(&s_mesh_map.path_map);
    HashMapN::init(&s_mesh_map.name_map);

    HashMapN::init(&s_texture_map.path_map);
    HashMapN::init(&s_texture_map.name_map);

    HashMapN::init(&s_string_map.path_map);
    HashMapN::init(&s_string_map.name_map);       

    HashMapN::init(&s_shader_map.path_map);
    HashMapN::init(&s_shader_map.name_map);   

    HashMapN::init(&s_sprite_map.path_map);
    HashMapN::init(&s_sprite_map.name_map);   

    HashMapN::init(&s_material_map.path_map);
    HashMapN::init(&s_material_map.name_map);   

    ::s_engine = engine;

}


void Internal::clean_asset()
{
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
    String,
    Shader,
    Sprite,
    Material,
};


static const char *asset_to_string(AssetType type)
{
    switch (type)
    {
        case AssetType::Mesh:     return "Mesh";
        case AssetType::Texture:  return "Texture";
        case AssetType::String:   return "String";
        case AssetType::Shader:   return "Shader";
        case AssetType::Sprite:   return "Sprite";
        case AssetType::Material: return "Material";
        

        default:
        {
            assert(false, "Unreachable");
            exit(1);
            return nullptr;
        }
    }
}




static U64 *get_check_path_hash(const char *path, void *path_map, AssetType type)
{
    char *buffer = Arena::top_alloc<char>(&g_memory.scratch_buffer, 1024);
    Platform::get_abs_path(path, buffer, 1024);

    HashMap<void *> *path_map_v = (HashMap<void *> *)path_map;

    U64 path_hash = HashMapN::hash_string(buffer);

    if (HashMapN::get_pointer(path_map_v, path_hash) != nullptr)
    {
        fprintf(stderr, "WARNING: tried to load %s that already exists or hash collision\n", asset_to_string(type));
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return nullptr;
    }

    U64 *path_hash_p = Arena::top_alloc<U64>(&g_memory.scratch_buffer);


    *path_hash_p = path_hash;

    return path_hash_p;
}


static U64 *get_check_name_hash(const char *name, void *name_map)
{
    HashMap<void *> *name_map_v = (HashMap<void *> *)name_map;

    U64 name_hash = HashMapN::hash_string(name);

    if (HashMapN::get_pointer(name_map_v, name_hash) != nullptr)
    {
        fprintf(stderr, "WARNING: tried to use \"%s\" which is already in use\n", name);
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return nullptr; 
    }

    U64 *name_hash_p = Arena::top_alloc<U64>(&g_memory.scratch_buffer);

    *name_hash_p = name_hash;

    return name_hash_p;
}


void Real::load_mesh(const char *name, const char *path)
{
    U64 *name_hash = get_check_name_hash(name, &s_mesh_map.name_map);
    U64 *path_hash = get_check_path_hash(path, &s_mesh_map.path_map, AssetType::Mesh); 

    if (name_hash == nullptr || path_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return;
    }

    Mesh *mesh = Arena::top_alloc<Mesh>(&g_memory.asset_buffer);
    const char *mesh_source = slurp_file(path, &g_memory.scratch_buffer);

    MeshN::init(mesh, mesh_source);

    HashMapN::set(&s_mesh_map.name_map, *name_hash, (void *)mesh);
    HashMapN::set(&s_mesh_map.path_map, *path_hash, (void *)mesh);

    fprintf(stderr, "NOTE: loaded %s \"%s\" from %s\n", asset_to_string(AssetType::Mesh), name, path);
    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::load_texture(const char *name, const char *path)
{
    U64 *name_hash = get_check_name_hash(name, &s_texture_map.name_map);
    U64 *path_hash = get_check_path_hash(path, &s_texture_map.path_map, AssetType::Texture); 

    if (name_hash == nullptr || path_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return;
    }

    Texture *texture = Arena::top_alloc<Texture>(&g_memory.asset_buffer);
    Real::init_texture(texture, path);

    HashMapN::set(&s_texture_map.path_map, *path_hash, (void *)texture);
    HashMapN::set(&s_texture_map.name_map, *name_hash, (void *)texture);

    fprintf(stderr, "NOTE: loaded %s \"%s\" from %s\n", asset_to_string(AssetType::Texture), name, path);
    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::load_vertex_shader_src(const char *name, const char *path)
{
    U64 *name_hash = get_check_name_hash(name, &s_string_map.name_map);
    U64 *path_hash = get_check_path_hash(path, &s_string_map.path_map, AssetType::String); 

    if (name_hash == nullptr || path_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return;
    }

    const char *src = slurp_file(path, &g_memory.asset_buffer);

    HashMapN::set(&s_string_map.path_map, *path_hash, (void *)src);
    HashMapN::set(&s_string_map.name_map, *name_hash, (void *)src);

    fprintf(stderr, "NOTE: loaded Vertex %s \"%s\" from %s\n", asset_to_string(AssetType::String), name, path);
    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::load_fragment_shader_src(const char *name, const char *path)
{
    U64 *name_hash = get_check_name_hash(name, &s_string_map.name_map);
    U64 *path_hash = get_check_path_hash(path, &s_string_map.path_map, AssetType::String); 

    if (name_hash == nullptr || path_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return;
    }

    const char *src = slurp_file(path, &g_memory.asset_buffer);

    HashMapN::set(&s_string_map.path_map, *path_hash, (void *)src);
    HashMapN::set(&s_string_map.name_map, *name_hash, (void *)src);
    
    fprintf(stderr, "NOTE: loaded Fragment %s \"%s\" from %s\n", asset_to_string(AssetType::String), name, path);
    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::init_shader(const char *name, const char *vert_src, const char *frag_src)
{
    U64 *name_hash = get_check_name_hash(name, &s_shader_map.name_map);

    if (name_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return;
    }

    Shader *shader = Arena::top_alloc<Shader>(&g_memory.asset_buffer);
    ShaderN::init(shader, vert_src, frag_src);

    HashMapN::set(&s_shader_map.name_map, *name_hash, (void *)shader);
    
    fprintf(stderr, "NOTE: initalized %s \"%s\"\n", asset_to_string(AssetType::Shader), name);
    Arena::clear_top_arena(&g_memory.scratch_buffer);
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

    U64 *name_hash = get_check_name_hash(name, &s_sprite_map.name_map);

    if (name_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
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

    HashMapN::set(&s_sprite_map.name_map, *name_hash, (void *)sprite);
    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::init_material(const char *name, Shader *shader, Texture *texture, shader_data_func *func)
{
    U64 *name_hash = get_check_name_hash(name, &s_material_map.name_map);

    if (name_hash == nullptr)
    {
        Arena::clear_top_arena(&g_memory.scratch_buffer);
        return;
    }

    Material *material = Arena::top_alloc<Material>(&g_memory.asset_buffer);

    MaterialN::init(material, shader, texture, func);

    HashMapN::set(&s_material_map.name_map, *name_hash, (void *)material);

    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


static void *get_item(const char *name, void *name_map)
{
    HashMap<void *> *name_map_v = (HashMap<void *> *)name_map;

    U64 hash = HashMapN::hash_string(name);
    void *pointer = HashMapN::get_value(name_map_v, hash);

    return pointer;    
}


Mesh *Real::get_mesh(const char *name)
{
    Mesh *mesh = (Mesh *)get_item(name, &s_mesh_map.name_map);

    if (mesh == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Mesh not found\n", name);
    }

    return mesh;
}


Texture *Real::get_texture(const char *name)
{
    Texture *texture = (Texture *)get_item(name, &s_texture_map.name_map);

    if (texture == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Texture not found\n", name);
    }

    return texture;
}


Sprite *Real::get_sprite(const char *name)
{
    Sprite *sprite = (Sprite *)get_item(name, &s_sprite_map.name_map);

    if (sprite == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Sprite not found\n", name);
    }

    return sprite;
}


const char *Real::get_vertex_src(const char *name)
{
    const char *vert_src = (const char *)get_item(name, &s_string_map.name_map);

    if (vert_src == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Vertex source not found\n", name);
    }

    return vert_src;    
}


const char *Real::get_fragment_src(const char *name)
{
    const char *frag_src = (const char *)get_item(name, &s_string_map.name_map);

    if (frag_src == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Fragment source not found\n", name);
    }

    return frag_src;    
}


Shader *Real::get_shader(const char *name)
{
    Shader *shader = (Shader *)get_item(name, &s_shader_map.name_map);

    if (shader == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Shader not found\n", name);
    }

    return shader;
}


Material *Real::get_material(const char *name)
{
    Material *material = (Material *)get_item(name, &s_material_map.name_map);

    if (material == nullptr)
    {
        fprintf(stderr, "WARNING: \"%s\" Material not found\n", name);
    }

    return material;
}


U32 Real::get_sprite_width(Sprite *sprite)
{
    return sprite->width;
}


U32 Real::get_sprite_height(Sprite *sprite)
{
    return sprite->height;
}

