#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Entry8;

typedef struct {
    u8 pad0[0x18858];
    Entry8 *unk18858;
} Ctx;

void func_80100304(s32 arg0);

void func_8016AE0C(Ctx *ctx, s32 index) {
    Entry8 *e = &ctx->unk18858[index];

    func_80100304(e->unk4);
}
