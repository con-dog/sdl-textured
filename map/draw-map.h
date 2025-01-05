#ifndef DRAW_MAP_H
#define DRAW_MAP_H

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

#include "map.h"
#include "../sdl/sdl-handler.h"
#include "../utils/utils.h"

extern void draw_top_down_wall_map(void);
extern void draw_filled_rects(SDL_Renderer *renderer, SDL_FRect *rects, unsigned int rects_count, RGBA_Colour *colour);

#endif