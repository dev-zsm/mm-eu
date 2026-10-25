#include "types.h"

typedef struct {
    u8 pad0[0x16960];
    s16 unk16960;
    s16 unk16962;
    s16 unk16964;
} Ctx;

typedef struct {
    u8 pad0[0xEF0];
    u32 unkEF0;
} Data;

extern Data D_801E6EF0;

void func_8012F628(Ctx *ctx) {
    s32 packed = (ctx->unk16960 & 0xF) << 8;

    packed |= (ctx->unk16962 & 0xF) << 4;
    packed |= ctx->unk16964 & 0xF;
    D_801E6EF0.unkEF0 = (D_801E6EF0.unkEF0 & 0xFFFF0000) | (packed & 0xFFFF);
}
