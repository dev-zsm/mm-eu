#include "types.h"

typedef struct {
    u8 pad0[0x222];
    u8 r;
    u8 g;
    u8 b;
    u8 r2;
    u8 g2;
    u8 b2;
} Skybox;

void Skybox_SetColors(Skybox *skybox, u8 r, u8 g, u8 b, u8 r2, u8 g2, u8 b2) {
    skybox->r = r;
    skybox->g = g;
    skybox->b = b;
    skybox->r2 = r2;
    skybox->g2 = g2;
    skybox->b2 = b2;
}
