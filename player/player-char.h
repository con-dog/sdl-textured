#ifndef PLAYER_CHAR_H
#define PLAYER_CHAR_H

#define PLAYER_W 8.0f
#define PLAYER_H 8.0f
#define PLAYER_SPEED 15.0f
#define PLAYER_ROTATION_SPEED 30.0f
#define PLAYER_INTERACTION_DISTANCE 4.0f
#define PLAYER_FOV 60.0f

#include <math.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include "../config/config.h"
#include "../map/map.h"
#include "../peripherals/peripheral-handler.h"
#include "../sdl/sdl-handler.h"
#include "../utils/utils.h"

typedef struct Player
{
  SDL_FRect rect;
  Vector_2D delta; // movement delta
  double angle;    // Angle in Degrees
} Player;

extern Player *get_player(void);
extern void draw_player(void);
extern void handle_player_movement(float delta_time);

#endif