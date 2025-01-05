#ifndef PRINT_DEBUG_H
#define PRINT_DEBUG_H

#include "../player/player-char.h"
#include "../sdl/sdl-handler.h"

extern void print_debug(
    float angle_radians,
    Point_2D *ray_start_point,
    Point_2D *ray_end_point,
    Vector_2D *ray_dir_vector,
    Vector_1D *step_x,
    Vector_1D *step_y,
    Vector_1D *delta_x,
    Vector_1D *delta_y,
    Point_1D *map_x,
    Point_1D *map_y,
    Vector_1D *dist_to_side_x,
    Vector_1D *dist_to_side_y,
    Point_1D *wall_x,
    Point_1D *wall_y)
{
  char debug_text[256];
  snprintf(debug_text, sizeof(debug_text),
           "angle_rads: %.2f\n\n"
           "ray.x0: %.2f\n"
           "ray.x_dir: %.2f\n"
           "step_x: %.2f\n"
           "delta_x: %.2f\n"
           "map_pos_x: %.2f\n"
           "wall_x: %.2f\n"
           "side_dist_x: %.2f\n\n",
           //  "ray.y0: %.2f\n"
           //  "ray.y_dir: %.2f\n"
           //  "step_y: %.2f\n"
           //  "map_pos_y: %.2f\n"
           //  "side_dist_y: %.2f",
           angle_radians,
           ray_start_point->x,
           ray_dir_vector->x,
           step_x->v,
           delta_x->v,
           map_x->p,
           wall_x->p,
           dist_to_side_x->v);

  TTF_Font *font = get_font();
  SDL_Renderer *renderer = get_renderer();

  SDL_Color text_color = {255, 0, 0, 255}; // Red text
  SDL_Surface *text_surface = TTF_RenderText_Blended_Wrapped(font, debug_text, strlen(debug_text), text_color, WINDOW_W / 4);

  if (text_surface)
  {
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (text_texture)
    {
      SDL_FRect text_rect = {
          WINDOW_W - text_surface->w - 10, // Position from right with 10px padding
          10,                              // Position from top with 10px padding
          text_surface->w,
          text_surface->h};

      SDL_RenderTexture(renderer, text_texture, NULL, &text_rect);
      SDL_DestroyTexture(text_texture);
    }
    SDL_DestroySurface(text_surface);
  }
}

#endif