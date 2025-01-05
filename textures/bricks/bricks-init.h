#ifndef BRICKS_INIT_H
#define BRICKS_INIT_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_hints.h>

#include "./var-1/brick-var-1.h"
#include "./var-2/brick-var-2.h"
#include "./var-3/brick-var-3.h"

extern SDL_Texture *get_brick_texture_1(void);
extern SDL_Texture *get_brick_texture_2(void);
extern SDL_Texture *get_brick_texture_3(void);
extern int brick_textures_init(SDL_Renderer *renderer);

#endif