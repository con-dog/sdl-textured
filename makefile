# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra $(shell pkg-config sdl3 sdl3-ttf --cflags)
LIBS = $(shell pkg-config sdl3 sdl3-ttf --libs)

# Directory structure
CONFIG_DIR = config
FONTS_DIR = fonts
MAP_DIR = map
PERIPHERALS_DIR = peripherals
PLAYER_DIR = player
SDL_DIR = sdl
TEXTURES_DIR = textures
UTILS_DIR = utils

# Texture subdirectories
BRICKS_DIR = $(TEXTURES_DIR)/bricks
PLANTS_DIR = $(TEXTURES_DIR)/plants

# Include paths
INCLUDES = \
    -I$(CONFIG_DIR) \
    -I$(MAP_DIR) \
    -I$(PERIPHERALS_DIR) \
    -I$(PLAYER_DIR) \
    -I$(SDL_DIR) \
    -I$(TEXTURES_DIR) \
    -I$(BRICKS_DIR) \
    -I$(BRICKS_DIR)/var-1 \
    -I$(BRICKS_DIR)/var-2 \
    -I$(BRICKS_DIR)/var-3 \
    -I$(PLANTS_DIR)/cactus \
    -I$(PLANTS_DIR)/flowers \
    -I$(PLANTS_DIR)/leaves \
    -I$(PLANTS_DIR)/trees \
    -I$(UTILS_DIR)

# Source files (excluding main)
CONFIG_SRC = $(shell find $(CONFIG_DIR) -name "*.c")
MAP_SRC = $(shell find $(MAP_DIR) -name "*.c")
PERIPHERAL_SRC = $(shell find $(PERIPHERALS_DIR) -name "*.c")
PLAYER_SRC = $(shell find $(PLAYER_DIR) -name "*.c")
SDL_SRC = $(shell find $(SDL_DIR) -name "*.c")
TEXTURE_SRC = $(shell find $(TEXTURES_DIR) -name "*.c")
UTIL_SRC = $(shell find $(UTILS_DIR) -name "*.c")

# All source files (excluding main)
SRC = $(CONFIG_SRC) $(MAP_SRC) $(PERIPHERAL_SRC) $(PLAYER_SRC) $(SDL_SRC) $(TEXTURE_SRC) $(UTIL_SRC)

# Object files (excluding main)
OBJ = $(SRC:.c=.o)

# Main target
TARGET = program

# Targets
all: $(TARGET)

$(TARGET): program.o $(OBJ)
	$(CC) $^ $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ) program.o

rebuild: clean all

.PHONY: all clean rebuild