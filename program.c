#include "program.h"

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

void update_display(void)
{
  SDL_Renderer *renderer = get_renderer();

  // Clear screen
  RGBA_Colour gray = {220, 220, 220, 255};
  SDL_SetRenderDrawColor(renderer, gray.r, gray.g, gray.b, gray.a);
  SDL_RenderClear(renderer);

  // Draw
  draw_top_down_wall_map();
  draw_player();
  // cast_rays();

  SDL_RenderPresent(renderer);
}

void run_game_loop(void)
{
  bool loopShouldStop = false;
  uint64_t previous_time = SDL_GetTicks();

  while (!loopShouldStop)
  {
    uint64_t current_time = SDL_GetTicks();
    float delta_time = (current_time - previous_time) / 1000.0f; // Convert to seconds
    previous_time = current_time;

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
      {
        loopShouldStop = true;
      }
    }

    handle_player_movement(delta_time);
    update_display();
  }
}

int main()
{
  sdl_init();

  SDL_Window *window = get_window();
  SDL_Renderer *renderer = get_renderer();
  TTF_Font *font = get_font();

  textures_init(renderer);

  run_game_loop();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  TTF_CloseFont(font);
  TTF_Quit();

  SDL_Quit();

  return 0;
}