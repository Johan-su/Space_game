#include "asset.hpp"
#include "../datastructures/hashmap.hpp"
#include "../platform/platform.hpp"
#include "../core.hpp"


static HashMap<void *> path_map;
static HashMap<void *> name_map;

static engine_data *engine;

void Internal::init_asset(engine_data *engine) // TODO(Johan): maybe pass in arena here and not directly access the global memory
{
    HashMapN::init(&path_map);
    HashMapN::init(&name_map);
    ::engine = engine;

    Internal::init_textures();
}


void Internal::clean_asset()
{
    Internal::clean_textures();
}


static const char *slurp_file(const char *path)
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);

    I64 file_length = ftell(file);

    rewind(file);

    char *slurped_file = Arena::top_alloc<char>(&g_memory.scratch_buffer, file_length + 1);    

    memset(slurped_file, 0, file_length + 1);
    fread(slurped_file, 1, file_length, file);


    fclose(file);
    return slurped_file; 
}




void Real::load_mesh(const char *path, const char *name)
{
    char *buffer = Arena::top_alloc<char>(&g_memory.scratch_buffer, 1024);
    Platform::get_abs_path(path, buffer, 1024);

    U64 path_hash = HashMapN::hash_string(buffer);
    U64 name_hash = HashMapN::hash_string(name);

    if (HashMapN::get_pointer(&name_map, name_hash) != NULL)
    {
        fprintf(stderr, "WARNING: tried to use \"%s\" which is already in use", name);
    }
    else if (HashMapN::get_pointer(&path_map, path_hash) != NULL)
    {
        fprintf(stderr, "WARNING: tried to load mesh that already exists or hash collision\n");
    }
    else
    {
        Mesh *mesh = Arena::top_alloc<Mesh>(&g_memory.asset_buffer);

        const char *mesh_source = slurp_file(path);

        MeshN::init(mesh, mesh_source);

        HashMapN::set(&path_map, path_hash, (void *)mesh);
        HashMapN::set(&name_map, name_hash, (void *)mesh);
    }

    Arena::clear_top_arena(&g_memory.scratch_buffer);
}


void Real::load_texture(const char *path, const char *name)
{
    char *path_buffer = Arena::top_alloc<char>(&g_memory.scratch_buffer, 1024);
    Platform::get_abs_path(path, path_buffer, 1024);

    U64 path_hash = HashMapN::hash_string(path_buffer);
    U64 name_hash = HashMapN::hash_string(name);

    if (HashMapN::get_pointer(&name_map, name_hash) != NULL)
    {
        fprintf(stderr, "WARNING: tried to use \"%s\" which is already in use", name);
    }
    else if (HashMapN::get_pointer(&path_map, path_hash) != NULL)
    {
        fprintf(stderr, "WARNING: tried to load mesh that already exists or hash collision\n");
    }
    else
    {
        Texture *texture = Arena::top_alloc<Texture>(&g_memory.asset_buffer);

        Internal::init_texture(engine->renderer, texture, path, path_hash);


        HashMapN::set(&path_map, path_hash, (void *)texture);
        HashMapN::set(&name_map, name_hash, (void *)texture);
    }

    //Arena::clear_top_arena(&g_memory.scratch_buffer);
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

    U64 name_hash = HashMapN::hash_string(name);

    if (HashMapN::get_pointer(&name_map, name_hash) != NULL)
    {
        fprintf(stderr, "WARNING: tried to use \"%s\" which already in use", name);
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

    HashMapN::set(&name_map, name_hash, (void *)sprite);
}


static void *get_item(const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    void *pointer = HashMapN::get_value(&name_map, hash);

    return pointer;    
}


Mesh *Real::get_mesh(const char *name)
{
    Mesh *mesh = (Mesh *)get_item(name);

    if (mesh == NULL)
    {
        fprintf(stderr, "WARNING: \"%s\" Mesh not found\n", name);
    }

    return mesh;
}


Texture *Real::get_texture(const char *name)
{
    Texture *texture = (Texture *)get_item(name);

    if (texture == NULL)
    {
        fprintf(stderr, "WARNING: \"%s\" Texture not found\n", name);
    }

    return texture;
}


Sprite *Real::get_sprite(const char *name)
{
    Sprite *sprite = (Sprite *)get_item(name);

    if (sprite == NULL)
    {
        fprintf(stderr, "WARNING: \"%s\" Sprite not found\n", name);
    }

    return sprite;
}




U32 Real::get_sprite_width(Sprite *sprite)
{
    return sprite->width;
}


U32 Real::get_sprite_height(Sprite *sprite)
{
    return sprite->height;
}

