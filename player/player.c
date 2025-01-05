#include "./player.h"

SDL_FRect player_rect;

Player player = {
    // Rect
    .rect.w = PLAYER_W,
    .rect.h = PLAYER_H,
    .rect.x = PLAYER_START_POS_X,
    .rect.y = PLAYER_START_POS_Y,
    // Movement
    .delta.x = 1,
    .delta.y = 0,
    // Angle
    .angle = 0,
};

extern void draw_player(void)
{
  SDL_Renderer *renderer = get_renderer();
  SDL_SetRenderDrawColor(renderer, 0, 128, 128, 255);
  SDL_RenderClear(renderer);
  SDL_RenderRect(renderer, &player.rect);
}
