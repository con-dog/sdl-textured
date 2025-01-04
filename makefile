# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra $(shell pkg-config sdl3 sdl3-ttf --cflags)
LIBS = $(shell pkg-config sdl3 sdl3-ttf --libs)

# Directory structure
TEXTURES_DIR = textures
FONTS_DIR = fonts

# Include paths
INCLUDES = \
    -I$(TEXTURES_DIR) \
    -I$(FONTS_DIR)

# Source files
TEXTURE_SRC = $(wildcard $(TEXTURES_DIR)/*.c)
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