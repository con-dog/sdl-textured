#ifndef TEXTURES_H
#define TEXTURES_H

#define TEXTURE_W 64
#define TEXTURE_H 64
#define BYTES_PER_PIXEL 4

typedef struct Gimp_RGBA_Image
{
  unsigned int width;
  unsigned int height;
  unsigned int bytes_per_pixel;
  unsigned char pixel_data[64 * 64 * 4 + 1];
} Gimp_RGBA_Image;

#endif
