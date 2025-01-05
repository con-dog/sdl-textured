#include "./map.h"

// clang-format off
const static Letter top_down_wall_map[GRID_SIZE] = {
  A, A, A, A, A, A, A, A,
  A, z, B, z, z, z, z, A,
  A, z, B, z, z, z, z, A,
  A, z, B, z, C, C, z, A,
  A, z, B, z, C, C, z, A,
  A, z, z, z, z, z, z, A,
  A, z, z, z, z, z, z, A,
  A, A, A, A, C, C, C, C,
};
// clang-format on

const extern Letter *get_top_down_wall_map(unsigned int *out_num_rows, unsigned int *out_num_cols)
{
  *out_num_rows = GRID_ROWS;
  *out_num_cols = GRID_COLS;
  return top_down_wall_map;
}