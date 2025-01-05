#ifndef UTILS_H
#define UTILS_H

#define CLOCKWISE 1.0f
#define ANTI_CLOCKWISE -1.0f
#define BACKWARDS -1.0f
#define FORWARDS 1.0f

typedef struct RGBA_Colour
{
  Uint8 r; // red
  Uint8 g; // green
  Uint8 b; // blue
  Uint8 a; // alpha
} RGBA_Colour;

typedef struct Vector_2D
{
  float x, y;
} Vector_2D;

typedef struct Point_2D
{
  float x, y;
} Point_2D;

typedef struct Vector_1D
{
  float v;
} Vector_1D;

typedef struct Point_1D
{
  float p;
} Point_1D;

#endif