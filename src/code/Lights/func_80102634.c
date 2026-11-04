#include "types.h"

typedef struct {
    u8 type;
    u8 unk1;
    u8 pad2[6];
    u8 r;
    u8 g;
    u8 b;
    u8 padB;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 padF[0x71];
} LightEntry;

typedef struct {
    u8 pad0[0x2B4];
    LightEntry *lights;
} GraphicsContext;

LightEntry *Lights_New(GraphicsContext *gfxCtx, u8 r, u8 g, u8 b) {
    LightEntry *entry;

    entry = gfxCtx->lights - 1;
    gfxCtx->lights = entry;

    entry->r = r;
    entry->r2 = r;
    entry->g = g;
    entry->g2 = g;
    entry->b = b;
    entry->b2 = b;
    entry->type = 0;
    entry->unk1 = 0;
    return entry;
}
