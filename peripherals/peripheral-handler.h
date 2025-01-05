#ifndef PERIPHERAL_HANDLER_H
#define PERIPHERAL_HANDLER_H

#define KEY_UP (1 << 0)
#define KEY_DOWN (1 << 1)
#define KEY_LEFT (1 << 2)
#define KEY_RIGHT (1 << 3)

#include <SDL3/SDL_keyboard.h>
#include <stdbool.h>
#include <stdlib.h>

uint8_t get_kb_arrow_input_state(void);

#endif