#ifndef DRAW_MAP_H
#define DRAW_MAP_H

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

#include "map.h"
#include "../sdl/sdl-handler.h"

typedef struct RGBA_Colour
{
  Uint8 r; // red
  Uint8 g; // green
  Uint8 b; // blue
  Uint8 a; // alpha
} RGBA_Colour;

extern void draw_filled_rects(SDL_Renderer *renderer, SDL_FRect *rects, unsigned int rects_count, RGBA_Colour *colour);
extern void draw_map(void);

#endif