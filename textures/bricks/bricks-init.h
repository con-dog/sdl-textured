#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#include "./var-1/brick-var-1.h"
#include "./var-2/brick-var-2.h"
#include "./var-3/brick-var-3.h"

static SDL_Texture *brick_var_1_texture = NULL;
static SDL_Texture *brick_var_2_texture = NULL;
static SDL_Texture *brick_var_3_texture = NULL;

extern SDL_Texture *get_brick_texture_1(void) {
  return brick_var_1_texture;
}
extern SDL_Texture *get_brick_texture_2(void) {
  return brick_var_2_texture;
}
extern SDL_Texture *get_brick_texture_3(void) {
  return brick_var_3_texture;
}

extern int brick_textures_init(SDL_Renderer *renderer)
{
  brick_var_1_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, TEXTURE_W, TEXTURE_H);
  brick_var_2_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, TEXTURE_W, TEXTURE_H);
  brick_var_3_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, TEXTURE_W, TEXTURE_H);

  if (!brick_var_1_texture || !brick_var_2_texture || !brick_var_3_texture)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Textures (Brick Textures) could not initialize! SDL_Texture Error: %s\n", SDL_GetError());
    return 3;
  }

  SDL_UpdateTexture(brick_var_1_texture, NULL, brick_var_1.pixel_data, TEXTURE_W * 4);
  SDL_UpdateTexture(brick_var_2_texture, NULL, brick_var_2.pixel_data, TEXTURE_W * 4);
  SDL_UpdateTexture(brick_var_3_texture, NULL, brick_var_3.pixel_data, TEXTURE_W * 4);

  return 0;
}