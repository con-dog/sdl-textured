#include "math-utils.h"

extern Radians convert_deg_to_rads(Degrees degrees)
{
  return degrees * (M_PI / 180.0f);
}