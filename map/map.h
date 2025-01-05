#ifndef MAP_H
#define MAP_H

#define CELL_SIZE 64.0f
#define GRID_ROWS 8
#define GRID_COLS 8
#define GRID_SIZE (GRID_ROWS * GRID_COLS)

// clang-format off
typedef enum Letter
{
  /* NO WALL */
  z,        // ! NO WALL
  /* BRICK WALLS */
  A, B, C, D, // * RED
  E, F, G, H,
  I, J, K, L,
  M, N, O,
  P, Q, R,
  S, T, U,
  V, W, X,
  Y, Z
} Letter;
// clang-format on

const static Letter top_down_wall_map[GRID_SIZE];
const extern Letter *get_top_down_wall_map(unsigned int *out_num_rows, unsigned int *out_num_cols);

#endif