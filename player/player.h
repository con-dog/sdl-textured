#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_W 8.0f
#define PLAYER_H 8.0f
#define PLAYER_SPEED 15.0f
#define PLAYER_ROTATION_SPEED 30.0f
#define PLAYER_INTERACTION_DISTANCE 5.0f

#include <SDL3/SDL_rect.h>

#include "../utils/utils.h"

typedef struct Player
{
  SDL_FRect rect;
  Vector_2D position; // xy
  Vector_2D movement; // deltas
  double    angle;    // Angle in Degrees
} Player;


#endif