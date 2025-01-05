#include "./player.h"

SDL_FRect player_rect;

Player player = {

};

const bool *
    keyboard_state;

// static void player_init(void)
// {
//   player_pos.x = 72.0f;
//   player_pos.y = 72.0f;
//   player_pos.angle = 0.0f;
//   player_pos.dx = cos(player_pos.angle) * 5;
//   player_pos.dy = sin(player_pos.angle) * 5;
//   player_rect.h = player_pos.h;
//   player_rect.w = player_pos.w;
//   player_rect.x = player_pos.x;
//   player_rect.y = player_pos.y;

//   SDL_SetRenderTarget(renderer, player_texture);
//   SDL_SetRenderDrawColor(renderer, 0, 128, 128, 255);
//   SDL_RenderClear(renderer);
//   SDL_SetRenderTarget(renderer, NULL);
// }