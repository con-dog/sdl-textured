#ifndef ALGEBRAIC_TYPES_H
#define ALGEBRAIC_TYPES_H

/*
 * 1 dimension
 */
typedef int Grid_Point_1D;
typedef float Plane_1D;
typedef float Point_1D;
typedef float Scalar;
typedef float Vector_1D;

/*
 * 2 dimensions
 */
typedef struct Grid_Point_2D
{
  Grid_Point_1D x;
  Grid_Point_1D y;
} Grid_Point_2D;

typedef struct
{
  Point_1D x;
  Point_1D y;
} Point_2D;

typedef struct
{
  Vector_1D x;
  Vector_1D y;
} Vector_2D;

typedef struct
{
  Point_2D start;
  Point_2D end;
} Line_2D;

typedef struct
{
  Point_2D origin;
  Scalar w;
  Scalar h;
} Rect_2D;

#endif