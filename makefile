# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra $(shell pkg-config sdl3 sdl3-ttf --cflags)
LIBS = $(shell pkg-config sdl3 sdl3-ttf --libs)

# Directory structure
CONFIG_DIR = config
DATA_DIR = data
IO_DIR = graphics
OBJECTS_DIR = objects
TEXTURES_DIR = textures
UTILS_DIR = utils

# Texture subdirectories
BRICKS_DIR = $(TEXTURES_DIR)/bricks

# Include paths
INCLUDES = \
    -I$(CONFIG_DIR) \
    -I$(DATA_DIR) \
    -I$(IO_DIR) \
    -I$(OBJECTS_DIR) \
    -I$(TEXTURES_DIR) \
    	-I$(BRICKS_DIR) \
    -I$(UTILS_DIR)

# Source files (excluding main)
CONFIG_SRC = $(wildcard $(CONFIG_DIR)/**/*.c)
DATA_SRC = $(wildcard $(DATA_DIR)/**/*.c)
IO_SRC = $(wildcard $(IO_DIR)/**/*.c)
OBJECTS_SRC = $(wildcard $(OBJECTS_DIR)/**/*.c)
TEXTURES_SRC = $(wildcard $(TEXTURES_DIR)/**/*.c)
UTILS_SRC = $(wildcard $(UTILS_DIR)/**/*.c)

# All source files (excluding main)
SRC = $(CONFIG_SRC) $(DATA_SRC) $(IO_SRC) $(OBJECTS_SRC) $(TEXTURES_SRC) $(UTILS_SRC)

# Object files (excluding main)
OBJ = $(SRC:.c=.o)

# Main target
TARGET = main

# Targets
all: $(TARGET)

$(TARGET): main.o $(OBJ)
	$(CC) $^ $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ) main.o
	find . -type f -name "*.o" -delete
	find . -type f -name "*.so" -delete
	find . -type f -name "*.a" -delete
	find . -type f -name "*.d" -delete
	find . -type f -name "*.gch" -delete

rebuild: clean all

.PHONY: all clean rebuild