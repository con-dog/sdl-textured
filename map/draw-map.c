#include "draw-map.h"

// Move to /draw or something
extern void draw_filled_rects(SDL_Renderer *renderer, SDL_FRect *rects, unsigned int rects_count, RGBA_Colour *colour)
{
  SDL_SetRenderDrawColor(renderer, colour->r, colour->g, colour->b, colour->a);
  SDL_RenderFillRects(renderer, rects, rects_count);
}

extern void draw_map(void)
{
  static bool initialized = false;
  static int black_rect_count = 0;
  static int white_rect_count = 0;
  static float offset = 0.1f;

  static RGBA_Colour black = {0, 0, 0, 255};
  static RGBA_Colour white = {255, 255, 255, 255};

  unsigned int wall_map_rows;
  unsigned int wall_map_cols;
  const Letter *top_down_wall_map = get_top_down_wall_map(&wall_map_rows, &wall_map_cols);
  unsigned int wall_map_total_size = wall_map_rows * wall_map_cols;

  SDL_FRect black_rects[wall_map_total_size];
  SDL_FRect white_rects[wall_map_total_size];

  if (!initialized)
  {
    for (int i = 0; i < GRID_ROWS; i++)
    {
      for (int j = 0; j < GRID_COLS; j++)
      {
        SDL_FRect rect;
        rect.h = CELL_SIZE * (1.0f - offset);
        rect.w = CELL_SIZE * (1.0f - offset);
        rect.x = (j * CELL_SIZE) + (CELL_SIZE * offset / 2);
        rect.y = (i * CELL_SIZE) + (CELL_SIZE * offset / 2);
        if (top_down_wall_map[i * wall_map_cols + j])
        {
          black_rects[black_rect_count++] = rect;
        }
        else
        {
          white_rects[white_rect_count++] = rect;
        }
      }
    }
    initialized = true;
  }

  draw_filled_rects(renderer, white_rects, white_rect_count, &white);
  draw_filled_rects(renderer, black_rects, black_rect_count, &black);
}
