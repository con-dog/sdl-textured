#ifndef PROGRAM_H
#define PROGRAM_H

// Window
#define WINDOW_W 1024
#define WINDOW_H 512
// Font
#define FONT_SMALL 12
// Map
#define CELL_SIZE 64.0f
#define GRID_ROWS 8
#define GRID_COLS 8
#define GRID_SIZE (GRID_ROWS * GRID_COLS)
// Player
#define PLAYER_W 8.0f
#define PLAYER_H 8.0f
#define MOTION_DELTA_MULTIPLIER 5
#define ROTATION_STEP 5.0f
#define PLAYER_SPEED 15.0f
#define PLAYER_ROTATION_SPEED 30.0f
#define PLAYER_INTERACTION_DISTANCE 4.0f
// Math Utils
#define CLOCKWISE 1
#define ANTI_CLOCKWISE -1
#define BACKWARDS -1.0f
#define FORWARDS 1.0f
// Input helpers
#define KEY_UP (1 << 0)
#define KEY_DOWN (1 << 1)
#define KEY_LEFT (1 << 2)
#define KEY_RIGHT (1 << 3)

#define TEXTURE_W 64
#define TEXTURE_H 64

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

typedef int8_t Rotation_Type;
typedef double Degrees;
typedef double Radians;

typedef float Vector_1D;
typedef struct Vector_2D
{
  float x, y;
} Vector_2D;

typedef float Point_1D;
typedef struct Point_2D
{
  Point_1D x, y;
} Point_2D;

typedef struct Line_2D
{
  Point_2D start;
  Point_2D stop;
} Line_2D;

typedef struct Rect_2D
{
  Point_2D tl;
  Point_2D tr;
  Point_2D bl;
  Point_2D br;
} Rect_2D;

typedef struct Player
{
  SDL_FRect rect;
  Vector_2D delta;
  Degrees angle; // degrees
} Player;

typedef struct Player_Pos
{
  float x, y, dx, dy; // Coordinates
  const float w, h;   // Width, Height
  double angle;       // Angle in Degrees
} Player_Pos;

typedef struct Ray_Pos
{
  float x0, x1, y0, y1;
  float x_dir, y_dir;
  const float length;
} Ray_Pos;

typedef struct DDA_Algo
{
  Vector_2D step;
  Vector_2D delta;
  Vector_2D map_pos;
  Vector_2D side_dist;
  Vector_2D wall;
} DDA_Algo;

//
typedef enum Letter
{
  z, // 0
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z
} Letter;

#endif
