#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

#include "../config/config.h"

extern SDL_Window *get_window(void);
extern SDL_Renderer *get_renderer(void);
extern int sdl_init(void);
