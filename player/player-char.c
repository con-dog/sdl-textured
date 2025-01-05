#include "./player-char.h"

static Player player = {
    // Rect
    .rect.w = PLAYER_W,
    .rect.h = PLAYER_H,
    .rect.x = PLAYER_START_POS_X,
    .rect.y = PLAYER_START_POS_Y,
    // Movement
    .delta.x = 5,
    .delta.y = 0,
    // Angle
    .angle = 0,
};

static void rotate_player(float rotation_type, float delta_time);
static void move_player(float direction, float delta_time);

extern Player *get_player(void)
{
  return &player;
}

extern void draw_player(void)
{
  SDL_Renderer *renderer = get_renderer();
  SDL_SetRenderDrawColor(renderer, 0, 128, 128, 255);
  SDL_RenderRect(renderer, &player.rect);
}

extern void handle_player_movement(float delta_time)
{
  uint8_t kb_arrows_state = get_kb_arrow_input_state();
  if (kb_arrows_state & KEY_LEFT)
  {
    rotate_player(ANTI_CLOCKWISE, delta_time);
  }
  if (kb_arrows_state & KEY_RIGHT)
  {
    rotate_player(CLOCKWISE, delta_time);
  }
  if (kb_arrows_state & KEY_UP)
  {
    move_player(FORWARDS, delta_time);
  }
  if (kb_arrows_state & KEY_DOWN)
  {
    move_player(BACKWARDS, delta_time);
  }
}

static void rotate_player(float rotation_type, float delta_time)
{
  player.angle = player.angle + (rotation_type * CAMERA_ROTATION_STEP * PLAYER_ROTATION_SPEED * delta_time);
  player.angle = player.angle < 0 ? 360.0f : player.angle > 360 ? 0
                                                                : player.angle;
  double angle_rads = player.angle * (M_PI / 180);
  player.delta.x = cos(angle_rads) * 5;
  player.delta.y = sin(angle_rads) * 5;
}

static void move_player(float direction, float delta_time)
{
  // Calculate potential new position
  float new_x = player.rect.x + (direction * player.delta.x * PLAYER_SPEED * delta_time);
  float new_y = player.rect.y + (direction * player.delta.y * PLAYER_SPEED * delta_time);

  // Calculate offsets from players hit-box
  int hitbox_top_left = top_down_wall_map[((int)((new_y - PLAYER_INTERACTION_DISTANCE) / CELL_SIZE) * GRID_COLS) + (int)((new_x - PLAYER_INTERACTION_DISTANCE) / CELL_SIZE)];
  int hitbox_top_right = top_down_wall_map[((int)((new_y - PLAYER_INTERACTION_DISTANCE) / CELL_SIZE) * GRID_COLS) + (int)((new_x + PLAYER_INTERACTION_DISTANCE) / CELL_SIZE)];
  int hitbox_bottom_left = top_down_wall_map[((int)((new_y + PLAYER_INTERACTION_DISTANCE) / CELL_SIZE) * GRID_COLS) + (int)((new_x - PLAYER_INTERACTION_DISTANCE) / CELL_SIZE)];
  int hitbox_bottom_right = top_down_wall_map[((int)((new_y + PLAYER_INTERACTION_DISTANCE) / CELL_SIZE) * GRID_COLS) + (int)((new_x + PLAYER_INTERACTION_DISTANCE) / CELL_SIZE)];

  // TODO - Allow it so player can still "slide" along walls
  // Only move it none of the corners would hit a wall
  printf("hitbox_top_left %d", hitbox_top_left);
  if (hitbox_top_left == z && hitbox_top_right == z &&
      hitbox_bottom_left == z && hitbox_bottom_right == z)
  {
    player.rect.x = new_x;
    player.rect.y = new_y;
  }
}
