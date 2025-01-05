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

#endif