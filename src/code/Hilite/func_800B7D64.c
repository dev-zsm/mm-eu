// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x2B0];
    s32 unk2B0;
} HiliteCtx;

s32 Hilite_Draw(s32, s32, s32, void *, s32, s32 *);

s32 Hilite_DrawOpa(s32 a0, s32 a1, s32 a2, HiliteCtx *arg3) {
    s32 sp2C;
    s32 pad[2];
    arg3->unk2B0 = Hilite_Draw(a0, a1, a2, arg3, arg3->unk2B0, &sp2C);
    return sp2C;
}
