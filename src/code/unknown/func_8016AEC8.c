#include "types.h"

typedef struct { s32 a, b, c, d, e; } E20;
typedef struct {
    u8 pad0[0xA4]; s16 unkA4;
    u8 pad1[0x1E58 - 0xA6]; s32 unk1E58, unk1E5C;
    u8 pad2[4]; s32 unk1E64;
} Dummy;
typedef struct {
    u8 pad0[0xA4]; s16 unkA4;
    u8 pad1[0x1E58 - 0xA6]; s32 unk1E58; s32 unk1E5C; s32 unk1E60; s32 unk1E64; s32 unk1E68; s32 unk1E6C; s32 unk1E70; s32 unk1E74;
} Ctx;

extern E20 D_801E6EF0[];
extern s32 func_8016AE44(s16);

void func_8016AEC8(Ctx *ctx) {
    E20 *e = (E20 *)((u8 *)&D_801E6EF0[func_8016AE44(ctx->unkA4)] + 0x3F68);
    s16 a;

    e->a = ctx->unk1E68;
    e->b = ctx->unk1E58;
    e->c = ctx->unk1E5C;
    a = ctx->unkA4;
    if (a == 0x18) {
        e = (E20 *)((u8 *)&D_801E6EF0[a] + 0x3F68);
    }
    e->e = ctx->unk1E74;
    e->d = ctx->unk1E6C;
}
