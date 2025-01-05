
#include "./sdl-handler.h"
#include "../config/config.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static TTF_Font *font;

extern SDL_Window *get_window(void)
{
  if (!window)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window not initialized. Call sdl_init() before using this function.");
  }
  return window;
}

extern SDL_Renderer *get_renderer(void)
{
  if (!renderer)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Renderer not initialized. Call sdl_init() before using this function.");
  }
  return renderer;
}

extern TTF_Font *get_font(void)
{
  return font;
}

extern int sdl_init()
{
  sdl_video_init();
  sdl_ttf_init();
  sdl_ttf_font_init();
  sdl_window_renderer_init();
}

static int sdl_video_init(void)
{
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_INIT_VIDEO could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 3;
  }
}

static int sdl_ttf_init(void)
{
  if (!TTF_Init())
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_ttf could not initialize! TTF_Error: %s\n", SDL_GetError());
    return 3;
  }
}

static int sdl_window_renderer_init(void)
{
  if (!SDL_CreateWindowAndRenderer("2.5D Raycaster", WINDOW_W, WINDOW_H, SDL_WINDOW_RESIZABLE, window, renderer))
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    return 3;
  }
}

static int sdl_ttf_font_init(void)
{
  font = TTF_OpenFont("../fonts/PressStart2P-Regular.ttf", FONT_SMALL);
  if (!font)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font! TTF_Error: %s\n", SDL_GetError());
    return 3;
  }
  return 0;
}