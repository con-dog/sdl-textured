#ifndef BRICKS_INIT_H
#define BRICKS_INIT_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_hints.h>

extern SDL_Texture *get_brick_texture_1(void);
extern SDL_Texture *get_brick_texture_2(void);
extern SDL_Texture *get_brick_texture_3(void);
extern int brick_textures_init(SDL_Renderer *renderer);

#endif