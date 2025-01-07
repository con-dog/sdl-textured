#ifndef MAIN_H
#define MAIN_H

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

#define JAGGED_GRID_ROWS 2
// Player
#define PLAYER_W 8.0f
#define PLAYER_H 8.0f
#define MOTION_DELTA_MULTIPLIER 5
#define ROTATION_STEP 5.0f
#define PLAYER_SPEED 15.0f
#define SPRINT_SPEED_INCREASE 15.0f
#define PLAYER_ROTATION_SPEED 30.0f
#define PLAYER_INTERACTION_DISTANCE 4.0f
#define PLAYER_FOV_DEG 60
#define PLAYER_FOV_DEG_INC 0.25f

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
#include <string.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

#include "./objects/types.h"
#include "./types/algebraic-types.h"
#include "./utils/math-utils.h"

typedef enum Wall_Surface_Hit
{
  HORIZONTAL,
  VERTICAL,
} Wall_Surface_Hit;

// clang-format off
typedef enum Wall_Type
{
  /* EMPTY */
  z,
  /* FULL */
  A, B, C, D,    // * BRICK
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
} Wall_Type;
// clang-format on

typedef struct
{
  int x_offset;        // Displacement in x direction in Grid
  int length;          // How many elements in this row
  Wall_Type *elements; // Pointer to the actual elements
} JaggedRow;

typedef struct
{
  int num_rows;    // Total number of rows
  JaggedRow *rows; // Array of row descriptors
} JaggedGrid;

#endif
