// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 b[0x3C00]; } Blk;
typedef struct { u8 pad0[0x4A70]; Blk blk[2]; } Ctx;
void func_80080CE0(u8 *, u8 *, s32, void *);
extern u8 D_AA0000[];
void func_800F4D14(Ctx *arg0, u8 arg1, s32 arg2) {
    func_80080CE0(arg0->blk[*((u8 *)arg0 + 0x167F8)].b + arg2, (arg1 << 7) - 0x1000 + D_AA0000, 0x80, arg0);
}
