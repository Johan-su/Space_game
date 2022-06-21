#include "Texture.hpp"
#include "assert.hpp"

#include <string.h>
#include <stdio.h>
void Texture_functions::init(textures_data *td)
{
    memset(td->texture_list, 0, sizeof(td->texture_list[0]) * MAX_TEXTURE_TYPES);
    memset(td->enum_to_texture, 0xFF, sizeof(td->enum_to_texture[0]) * MAX_TEXTURE_TYPES);

    memset(td->sprite_list, 0xFF, sizeof(td->sprite_list[0]) * MAX_SPRITE_TYPES);
    memset(td->enum_to_sprite, 0xFF, sizeof(td->enum_to_sprite[0]) * MAX_SPRITE_TYPES);
    td->texture_count = 0;
    td->sprite_count = 0;
}


void Texture_functions::clean(textures_data *td)
{
    for(size_t i = 0; i < td->texture_count; ++i)
    {
        SDL_DestroyTexture(td->texture_list[i]);
    }
}


void Texture_functions::load_texture(SDL_Renderer *renderer, textures_data *td, U32 enum_id, const char *path)
{
    

    SDL_Surface *surface = SDL_LoadBMP(path);
    if(surface)
    {
        printf("NOTE: Loaded texture file from %s\n", path);
    } 
    else
    {
        fprintf(stderr, "ERROR: failed to load surface : %s\n", SDL_GetError());
        exit(1);
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        fprintf(stderr, "ERROR: failed to load texture : %s\n", SDL_GetError());
        exit(1);
    }

    td->enum_to_texture[enum_id] = td->texture_count;
    td->texture_list[td->texture_count++] = texture;
}


void Texture_functions::init_sprite(textures_data *td, U32 sprite_id, U32 texture_id, U32 x, U32 y, U32 w, U32 h)
{
    assert(sprite_id <= MAX_SPRITE_TYPES, "sprite id too big");

    td->enum_to_sprite[sprite_id] = td->sprite_count;

    assert(texture_id <= MAX_TEXTURE_TYPES, "texture id too big");

    Tex_Sprite sprite = Tex_Sprite();

    sprite.x = x;
    sprite.y = y;
    sprite.w = w;
    sprite.h = h;

    sprite.texture_index = texture_id;

    td->sprite_list[td->sprite_count] = sprite;

}

SDL_Texture *Texture_functions::get_texture(textures_data *td, U32 id)
{
    assert(id <= MAX_TEXTURE_TYPES, "id cannot be greater than MAX_TEXTURE_TYPES");
    return td->texture_list[td->enum_to_texture[id]];
}

Tex_Sprite *Texture_functions::get_sprite(textures_data *td, U32 id)
{
    assert(id <= MAX_SPRITE_TYPES, "id cannot be greater than MAX_SPRITE_TYPES");
    return &td->sprite_list[td->enum_to_sprite[id]];
}



