#include "types.h"

typedef struct {
    u8 type;
    u8 pad1;
    u8 pad2[6];
    u8 r1;
    u8 g1;
    u8 b1;
    u8 pad3;
    u8 r2;
    u8 g2;
    u8 b2;
} LightsData;

void Lights_Reset(LightsData *arg0, u8 r, u8 g, u8 b) {
    arg0->r2 = r;
    arg0->r1 = r;
    arg0->g2 = g;
    arg0->g1 = g;
    arg0->b2 = b;
    arg0->b1 = b;
    arg0->pad1 = 0;
}
