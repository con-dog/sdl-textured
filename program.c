#include "program.h"

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
  cast_rays();

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