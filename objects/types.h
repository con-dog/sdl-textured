#ifndef OBJECT_TYPES_H
#define OBJECT_TYPES_H

#include <SDL3/SDL_render.h>

#include "../types/algebraic-types.h"
#include "../utils/math-utils.h"

typedef struct
{
  Point_2D tl;
  Point_2D tr;
  Point_2D bl;
  Point_2D br;
} Hit_Box;

typedef struct Player
{
  SDL_FRect rect;
  Vector_2D delta;
  Degrees angle; // degrees
} Player;

#endif