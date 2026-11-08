// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ctx {
    /* 0x00000 */ u8 pad0[0x1877C];
    /* 0x1877C */ void (*unk1877C)(struct Ctx *, void *, s32);
} Ctx;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x394];
    /* 0x394 */ u8 unk394;
} Ea;

void func_80000934(Ea *this, Ctx *ctx) {
    if (this->unk394 != 0) {
        ctx->unk1877C(ctx, this, 6);
    }
}
