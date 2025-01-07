#ifndef DATA_GRID_H
#define DATA_GRID_H

#define GRID_CELL_SIZE 64.0f
#define MAX_GRID_ROWS 100
#define MAX_GRID_COLS 100
#define MAX_GRID_SIZE (MAX_GRID_ROWS * MAX_GRID_COLS)

#include "../wall/types.h"

typedef struct
{
  int x_offset;        // Displacement in x direction when elements shown in grid
  int length;          // How many elements in this row
  Wall_Type *elements; // Pointer to the elements
} Jagged_Row;

typedef struct
{
  int num_rows;     // Total number of rows
  Jagged_Row *rows; // Array of Jagged_Rows
} Jagged_Grid;

#endif