# SDL3 2.5D Raycasting Engine With Textures

![Preview](https://github.com/con-dog/sdl-textured/blob/88a4a451aa799864a2b6c6f975da92f160baa858/media/phase-3/Screen%20Recording%202025-01-06%20at%207.53.50%E2%80%AFPM.gif)

![Preview](https://github.com/con-dog/sdl-textured/blob/88a4a451aa799864a2b6c6f975da92f160baa858/media/phase-3/phase-3.png)

A simple 2.5D raycaster built with C and SDL3 - similar to Wolfenstein engine.

Can walk and sprint around a maze with wall collisions. Requires SDL3 and SDL3_ttf to build and run.

## Limitations

- Wall Map requires a "rectangular" array to calculate wall distances and indexes
  - Therefore all maps must be rectangular/square - no funky shapes
  - Next version will use Jagged arrays to have maps of any real shape

Heres some pseudocode for the jagged array approach I want (changeable first index)
```c
// clang-format off
const static Wall_Type grid_walls[GRID_SIZE] = {
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

// clang-format off
const static Wall_Type jagged_var_start_index_grid_walls[GRID_SIZE] = {
  A, A, A, A,
        A,
     A, z,
        A, z, B, z, C, C, z, A,
  A, C, z, A,
           A, z,
        A, A, A, A, C,
};
// clang-format on