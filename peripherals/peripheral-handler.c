#include "./peripheral-handler.h"

const bool *keyboard_state;

uint8_t get_kb_arrow_input_state(void)
{
  keyboard_state = SDL_GetKeyboardState(NULL);

  uint8_t state = 0b0;
  if (keyboard_state[SDL_SCANCODE_UP])
    state |= KEY_UP;
  if (keyboard_state[SDL_SCANCODE_DOWN])
    state |= KEY_DOWN;
  if (keyboard_state[SDL_SCANCODE_LEFT])
    state |= KEY_LEFT;
  if (keyboard_state[SDL_SCANCODE_RIGHT])
    state |= KEY_RIGHT;
  return state;
}
