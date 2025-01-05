#ifndef PROGRAM_H
#define PROGRAM_H

// Player
// #define PLAYER_SIZE 8.0f
// #define ROTATION_STEP 5.0f
// #define PLAYER_SPEED 15.0f
// #define PLAYER_ROTATION_SPEED 30.0f
// #define INTERACTION_DISTANCE 5.0f
// Math Utils
// #define CLOCKWISE 1.0f
// #define ANTI_CLOCKWISE -1.0f
// #define BACKWARDS -1.0f
// #define FORWARDS 1.0f
// Input helpers
#define KEY_UP (1 << 0)
#define KEY_DOWN (1 << 1)
#define KEY_LEFT (1 << 2)
#define KEY_RIGHT (1 << 3)

// typedef struct Player_Pos
// {
//   float x, y, dx, dy; // Coordinates
//   const float w, h;   // Width, Height
//   double angle;       // Angle in Degrees
// } Player_Pos;

typedef struct Ray_Pos
{
  float x0, x1, y0, y1;
  float x_dir, y_dir;
  const float length;
} Ray_Pos;

// typedef struct Vector_2D
// {
//   float x, y;
// } Vector_2D;

typedef struct DDA_Algo
{
  Vector_2D step;
  Vector_2D delta;
  Vector_2D map_pos;
  Vector_2D side_dist;
  Vector_2D wall;
} DDA_Algo;

#endif
