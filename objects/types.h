#ifndef OBJECT_TYPES_H
#define OBJECT_TYPES_H

#include "../types/algebraic-types.h"

typedef struct Hit_Box
{
  Point_2D tl;
  Point_2D tr;
  Point_2D bl;
  Point_2D br;
} Hit_Box;

typedef struct Grid_Hit_Box
{
  Grid_Point_2D tl;
  Grid_Point_2D tr;
  Grid_Point_2D bl;
  Grid_Point_2D br;
} Grid_Hit_Box;

#endif