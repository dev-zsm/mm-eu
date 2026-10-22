// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 r;
    u8 g;
    u8 b;
    u8 pad_B;
    s16 radius;
} PointLight;

void Lights_PointSetColorAndRadius(PointLight *light, u8 r, u8 g, u8 b, s16 radius) {
    light->r = r;
    light->g = g;
    light->b = b;
    light->radius = radius;
}
