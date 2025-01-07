#ifndef OBJECT_TYPES_H
#define OBJECT_TYPES_H

#include "../types/algebraic-types.h"

typedef struct
{
  Point_2D tl;
  Point_2D tr;
  Point_2D bl;
  Point_2D br;
} Hit_Box;

#endif