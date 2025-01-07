#ifndef DATA_WALL_H
#define DATA_WALL_H

// clang-format off
typedef enum Wall_Type
{
  /* EMPTY */
  z,
  /* FULL */
  A, B, C, D,    // * BRICK
  E, F, G, H,
  I, J, K, L,
  M, N, O, P,
  Q, R, S, T,
  U, V, W, X,
  Y, Z
} Wall_Type;
// clang-format on

typedef enum Wall_Surface
{
  WS_HORIZONTAL,
  WS_VERTICAL,
} Wall_Surface;

#endif