#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_render.h>

#include "../config/config.h"

extern SDL_Window *get_window(void);
extern SDL_Renderer *get_renderer(void);
extern TTF_Font *get_font(void);
extern void sdl_init(void);

#endif