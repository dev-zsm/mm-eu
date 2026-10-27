#include "types.h"

typedef struct {
    u8 pad0[0xB20];
    u16 flags[20];
} Sub;

typedef struct {
    u8 pad0[0x18000];
    Sub sub;
} Ctx;

void CutsceneFlags_UnsetAll(Ctx *ctx) {
    u8 i;

    for (i = 0; i < 20; i++) {
        ctx->sub.flags[i] = 0;
    }
}
