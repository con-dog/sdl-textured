#ifndef GRID_TYPES_H
#define GRID_TYPES_H

#include "../wall/types.h"

typedef struct
{
  int length;          // How many elements in this row
  Wall_Type *elements; // Pointer to the elements
} Jagged_Row;

typedef struct
{
  int num_rows;     // Total number of rows
  Jagged_Row *rows; // Array of Jagged_Rows
} Jagged_Grid;

#endif