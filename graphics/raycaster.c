#include "raycaster.h"
#include <stdio.h>

/*
 * Cast ray/s from player to wall using Digital Differential Analysis Algorithm
 */
static void draw_ray(Point_2D *start, Point_2D *stop);
static void print_text(
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
    Point_1D *wall_y);

extern void cast_rays(void)
{
  Player *player = get_player();

  float rays_start_angle = player->angle - PLAYER_FOV / 2;
  float rays_end_angle = player->angle + PLAYER_FOV / 2;

  // for (float current_angle = player->angle; current_angle <= rays_end_angle; current_angle += 60)
  for (int i = 0; i < 1; i++)
  {
    float current_angle = player->angle;
    float angle_rads = current_angle * (M_PI / 180.0f);

    Point_2D ray_start_point = {
        .x = player->rect.x + (PLAYER_W / 2), // Center of Player
        .y = player->rect.y + (PLAYER_H / 2), // Center of Player
    };
    Point_2D ray_end_point;
    Vector_2D ray_direction_vector = {
        .x = cos(angle_rads),
        .y = sin(angle_rads),
    };

    Vector_1D step_x = {.v = (ray_direction_vector.x >= 0) ? 1 : -1};
    Vector_1D step_y = {.v = (ray_direction_vector.y >= 0) ? 1 : -1};
    // Distance along ray from one x or y side to next
    Vector_1D delta_x = {.v = fabs(1.0 / ray_direction_vector.x)};
    Vector_1D delta_y = {.v = fabs(1.0 / ray_direction_vector.y)};
    Point_1D map_x = {.p = floorf(ray_start_point.x / CELL_SIZE)};
    Point_1D map_y = {.p = floorf(ray_start_point.y / CELL_SIZE)};
    Vector_1D dist_to_side_x = {.v = (ray_direction_vector.x < 0) ? ((ray_start_point.x / CELL_SIZE) - map_x.p) * delta_x.v
                                                                  : (map_x.p + 1.0f - (ray_start_point.x / CELL_SIZE)) * delta_x.v};
    Vector_1D dist_to_side_y = {.v = (ray_direction_vector.y < 0) ? ((ray_start_point.y / CELL_SIZE) - map_y.p) * delta_y.v
                                                                  : (map_y.p + 1.0f - (ray_start_point.y / CELL_SIZE)) * delta_y.v};
    Point_1D wall_x = {.p = ray_start_point.x};
    Point_1D wall_y = {.p = ray_start_point.y};

    bool hit = false;
    while (!hit)
    {
      if (dist_to_side_x.v < dist_to_side_y.v)
      {
        // Calculate exact wall hit position for x-side
        wall_x.p = (ray_direction_vector.x < 0)
                       ? map_x.p * CELL_SIZE
                       : (map_x.p + 1) * CELL_SIZE;
        wall_y.p = ray_start_point.y + (wall_x.p - ray_start_point.x) * ray_direction_vector.y / ray_direction_vector.x;
        dist_to_side_x.v += delta_x.v;
        map_x.p += step_x.v;
        printf("AAAA\n");
      }
      else
      {
        wall_y.p = (ray_direction_vector.y < 0)
                       ? map_y.p * CELL_SIZE
                       : (map_y.p + 1) * CELL_SIZE;
        wall_x.p = ray_start_point.x + (wall_y.p - ray_start_point.y) * ray_direction_vector.x / ray_direction_vector.y;
        dist_to_side_y.v += delta_y.v;
        map_y.p += step_y.v;
        printf("BBBB\n");
      }

      ray_end_point.x = wall_x.p;
      ray_end_point.y = wall_y.p;

      if (top_down_wall_map[GRID_ROWS * (int)map_y.p + (int)map_x.p] == A)
      {
        hit = true;
        break;
      }
    }
    draw_ray(&ray_start_point, &ray_end_point); // Move this here

    print_text(
        angle_rads,
        &ray_start_point,
        &ray_end_point,
        &ray_direction_vector,
        &step_x,
        &step_y,
        &delta_x,
        &delta_y,
        &map_x,
        &map_y,
        &dist_to_side_x,
        &dist_to_side_y,
        &wall_x,
        &wall_y);
  }
}

static void draw_ray(Point_2D *start, Point_2D *stop)
{
  SDL_Renderer *renderer = get_renderer();
  RGBA_Colour ray = {0, 255, 0, 255};
  SDL_SetRenderDrawColor(renderer, ray.r, ray.g, ray.b, ray.a);
  SDL_RenderLine(renderer, start->x, start->y, stop->x, stop->y);
}

static void print_text(
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

// static void print_text(float angle_radians, Ray_Pos ray, DDA_Algo dda)
// {
//   char debug_text[256];
//   snprintf(debug_text, sizeof(debug_text),
//            "angle_rads: %.2f\n\n"
//            "ray.x0: %.2f\n"
//            "ray.x_dir: %.2f\n"
//            "step_x: %.2f\n"
//            "map_pos_x: %.2f\n"
//            "side_dist_x: %.2f\n\n"
//            "ray.y0: %.2f\n"
//            "ray.y_dir: %.2f\n"
//            "step_y: %.2f\n"
//            "map_pos_y: %.2f\n"
//            "side_dist_y: %.2f",
//            angle_radians, ray.x0, ray.x_dir, dda.step.x, dda.map_pos.x, dda.side_dist.x, ray.y0, ray.y_dir, dda.step.y, dda.map_pos.y, dda.side_dist.y);

//   SDL_Color text_color = {255, 0, 0, 255}; // Red text
//   SDL_Surface *text_surface = TTF_RenderText_Blended_Wrapped(font, debug_text, strlen(debug_text), text_color, WINDOW_W / 4);

//   if (text_surface)
//   {
//     SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
//     if (text_texture)
//     {
//       SDL_FRect text_rect = {
//           WINDOW_W - text_surface->w - 10, // Position from right with 10px padding
//           10,                              // Position from top with 10px padding
//           text_surface->w,
//           text_surface->h};

//       SDL_RenderTexture(renderer, text_texture, NULL, &text_rect);
//       SDL_DestroyTexture(text_texture);
//     }
//     SDL_DestroySurface(text_surface);
//   }
// }

// // Draw a ray from player to wall using DDA (Digital Differential Analysis) algorithm
// static void draw_dda_ray(void)
// {
//   // Calculate start and end angles for 60° FOV centered on player angle
//   float start_angle = player_pos.angle - 30; // 30° left of center
//   float end_angle = player_pos.angle + 30;   // 30° right of center
//   Uint8 r, g, b;
//   for (float current_angle = start_angle; current_angle <= end_angle; current_angle += 0.25f)
//   {
//     float angle_radians = current_angle * (M_PI / 180.0);

//     Ray_Pos ray = {
//         // Center ray start position on player
//         .x0 = player_pos.x + (PLAYER_SIZE / 2),
//         .y0 = player_pos.y + (PLAYER_SIZE / 2),
//         // Calculate ray direction vector from angle
//         .x_dir = cos(angle_radians),
//         .y_dir = sin(angle_radians),
//     };

//     DDA_Algo dda = {
//         // Determine step direction (+1 or -1) for x and y based on ray direction
//         .step.x = (ray.x_dir >= 0) ? 1 : -1,
//         .step.y = (ray.y_dir >= 0) ? 1 : -1,
//         // Calculate delta distances - distance along ray from one x or y side to next
//         .delta.x = fabs(1.0 / ray.x_dir),
//         .delta.y = fabs(1.0 / ray.y_dir),
//         // Get player's current map grid cell position
//         .map_pos.x = floorf(ray.x0 / CELL_SIZE),
//         .map_pos.y = floorf(ray.y0 / CELL_SIZE),
//         // Calculate initial side distances - distance from start to first x or y grid line
//         .side_dist.x = (ray.x_dir < 0)
//                            ? ((ray.x0 / CELL_SIZE) - dda.map_pos.x) * dda.delta.x
//                            : (dda.map_pos.x + 1.0f - (ray.x0 / CELL_SIZE)) * dda.delta.x,
//         .side_dist.y = (ray.y_dir < 0)
//                            ? ((ray.y0 / CELL_SIZE) - dda.map_pos.y) * dda.delta.y
//                            : (dda.map_pos.y + 1.0f - (ray.y0 / CELL_SIZE)) * dda.delta.y,
//         .wall.x = ray.x0,
//         .wall.y = ray.y0,
//     };

//     print_text(angle_radians, ray, dda);

//     // Track if we've hit a wall and which side we hit
//     int hit = 0;
//     int side;
//     // DDA loop - step through grid cells until we hit a wall
//     while (!hit)
//     {
//       // Step in x or y direction depending on which side distance is smaller
//       if (dda.side_dist.x < dda.side_dist.y)
//       {
//         // Calculate exact wall hit position for x-side
//         dda.wall.x = (ray.x_dir < 0) ? (dda.map_pos.x * CELL_SIZE) : ((dda.map_pos.x + 1) * CELL_SIZE);
//         dda.wall.y = ray.y0 + (dda.wall.x - ray.x0) * ray.y_dir / ray.x_dir;
//         dda.side_dist.x += dda.delta.x;
//         dda.map_pos.x += dda.step.x;
//         side = 0;
//       }
//       else
//       {
//         // Calculate exact wall hit position for y-side
//         dda.wall.y = (ray.y_dir < 0) ? (dda.map_pos.y * CELL_SIZE) : ((dda.map_pos.y + 1) * CELL_SIZE);
//         dda.wall.x = ray.x0 + (dda.wall.y - ray.y0) * ray.x_dir / ray.y_dir;
//         dda.side_dist.y += dda.delta.y;
//         dda.map_pos.y += dda.step.y;
//         side = 1;
//       }

//       ray.x1 = dda.wall.x;
//       ray.y1 = dda.wall.y;

//       // Check if we've hit a wall
//       if (map_2D_wall[GRID_ROWS * (int)dda.map_pos.y + (int)dda.map_pos.x] != z)
//       {
//         hit = 1;
//       }
//     }

//     SDL_SetRenderDrawColor(renderer, r, g, b, 255);
//     // Draw the ray from player to wall hit point
//     SDL_RenderLine(renderer, ray.x0, ray.y0, ray.x1, ray.y1);

//     float hypotenuse = sqrt(pow(ray.x1 - ray.x0, 2) + pow(ray.y1 - ray.y0, 2));
//     // Calculate the x position for this ray's vertical line
//     // Map the angle from [-30, 30] to screen position [WINDOW_W/2, WINDOW_W]
//     float ray_screen_pos = ((current_angle - start_angle) / 60.0f) * (WINDOW_W / 2) + WINDOW_W / 2;

//     // Calculate perpendicular distance to avoid fisheye effect
//     float perp_distance = hypotenuse * cos((current_angle - player_pos.angle) * (M_PI / 180.0));

//     // Calculate line height using perpendicular distance
//     float line_h = (CELL_SIZE * WINDOW_H) / perp_distance;
//     if (line_h > WINDOW_H)
//       line_h = WINDOW_H;

//     // Calculate where to start drawing the vertical line so it's centered
//     float line_offset = (WINDOW_H - line_h) / 2;

//     // Calculate the width of each vertical strip
//     float strip_width = (WINDOW_W / 2) / ((end_angle - start_angle) / 0.25f);

//     SDL_FRect wall_rect = {
//         .x = (int)ray_screen_pos,
//         .y = (int)line_offset,
//         .w = (int)ceil(strip_width),
//         .h = (int)line_h,
//     };

//     float wall_x;
//     if (side == 0)
//     {
//       wall_x = dda.wall.y; // For vertical walls, use the calculated y position
//     }
//     else
//     {
//       wall_x = dda.wall.x; // For horizontal walls, use the calculated x position
//     }

//     wall_x = wall_x / CELL_SIZE;
//     wall_x -= floor(wall_x);

//     int tex_x = (int)(wall_x * TEXTURE_W);

//     switch (map_2D_wall[GRID_ROWS * (int)dda.map_pos.y + (int)dda.map_pos.x])
//     {
//     case A:
//     {
//       SDL_FRect src_rect = {
//           .x = tex_x,
//           .y = 0,
//           .w = 1,
//           .h = TEXTURE_H};

//       SDL_RenderTexture(renderer, brick_var_1_texture, &src_rect, &wall_rect);
//       break;
//     }
//     case B:
//     {
//       SDL_FRect src_rect = {
//           .x = tex_x,
//           .y = 0,
//           .w = 1,
//           .h = TEXTURE_H};

//       SDL_RenderTexture(renderer, brick_var_2_texture, &src_rect, &wall_rect);
//       break;
//     }
//     case C:
//     {
//       SDL_FRect src_rect = {
//           .x = tex_x,
//           .y = 0,
//           .w = 1,
//           .h = TEXTURE_H};

//       SDL_RenderTexture(renderer, brick_var_3_texture, &src_rect, &wall_rect);
//       break;
//     }
//     default:
//       SDL_SetRenderDrawColor(renderer, 128, 128, 0, 255);
//       SDL_RenderFillRect(renderer, &wall_rect);
//     }
//   }
// }
