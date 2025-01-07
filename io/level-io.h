#ifndef LEVEL_IO_H
#define LEVEL_IO_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../data/grid/constants.h"
#include "../data/grid/types.h"

extern Jagged_Grid *read_grid_csv_file(const char *filename);
extern void free_jagged_grid(Jagged_Grid *grid);
extern void print_jagged_grid(const Jagged_Grid *grid);

#endif