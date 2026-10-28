#include "types.h"

typedef struct {
    u8 pad0[0x11F26];
    u8 unk11F26;
    u8 pad11F27[0x12027 - 0x11F27];
    u8 unk12027;
    s16 unk12028;
    u8 pad1202A[0x12044 - 0x1202A];
    s32 unk12044;
} Sub;
typedef struct {
    u8 pad0[0x4908];
    Sub sub;
} Ctx;
typedef struct {
    u8 pad0[0x16936];
    s16 unk16936;
    u16 unk16938;
} Ctx2;
extern void func_80151168(Ctx *ctx, u16 a1);
void func_80151DF4(Ctx *ctx, u16 a1, s32 a2) {
    Sub *sub;
    Sub *new_var;
    new_var = &ctx->sub;
    ((Ctx2 *) ctx)->unk16938 = 0xFFFF;
    func_80151168(ctx, a1);
    sub = new_var;
    sub->unk12044 = a2;
    sub->unk11F26 = 1;
    sub->unk12027 = 0;
    sub->unk12028 = 0;
    ((Ctx2 *) ctx)->unk16936 = 0;
}
