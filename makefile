# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra $(shell pkg-config sdl3 sdl3-ttf --cflags)
LIBS = $(shell pkg-config sdl3 sdl3-ttf --libs)

# Directory structure
TEXTURES_DIR = textures
FONTS_DIR = fonts
MEDIA_DIR = media

# Texture subdirectories
BRICKS_DIR = $(TEXTURES_DIR)/bricks
PLANTS_DIR = $(TEXTURES_DIR)/plants

# Include paths
INCLUDES = \
    -I$(TEXTURES_DIR) \
    -I$(FONTS_DIR) \
    -I$(BRICKS_DIR)/var-1 \
    -I$(PLANTS_DIR)/cactus \
    -I$(PLANTS_DIR)/flowers \
    -I$(PLANTS_DIR)/leaves \
    -I$(PLANTS_DIR)/trees

# Source files (recursively find all .c files in textures directory)
TEXTURE_SRC = $(shell find $(TEXTURES_DIR) -name "*.c")
MAIN_SRC = program.c

# All source files
SRC = $(MAIN_SRC) $(TEXTURE_SRC)

# Object files
OBJ = $(SRC:.c=.o)

# Main target
TARGET = program

# Targets
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

rebuild: clean all

.PHONY: all clean rebuild