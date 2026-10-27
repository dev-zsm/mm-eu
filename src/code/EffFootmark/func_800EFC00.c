#include "types.h"

typedef struct {
    u8 pad0[0x40];
    s32 actor;
    f32 x, y, z;
    u8 flagA;
    u8 flagB;
    u8 pad12[4];
    s16 s16a;
    s16 s18;
    u8 pad1A[6];
} Footmark;

typedef struct {
    u8 pad0[0x2138];
    Footmark footmarks[100];
} Ctx;

void EffFootmark_Init(Ctx *ctx) {
    Footmark *f;
    s32 i;

    for (f = ctx->footmarks, i = 0; i < 100; i++, f++) {
        f->actor = 0;
        f->x = 0.0f;
        f->y = 0.0f;
        f->z = 0.0f;
        f->flagA = 0;
        f->flagB = 0;
        f->s16a = 0;
        f->s18 = 0;
    }
}
