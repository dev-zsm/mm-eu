// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x2C0];
    s32 unk2C0;
} Ctx;

s32 Hilite_Draw(s32, s32, s32, Ctx *, s32, s32 *);

s32 Hilite_DrawXlu(s32 a0, s32 a1, s32 a2, Ctx *a3) {
    s32 sp2C; s32 pad[2];

    a3->unk2C0 = Hilite_Draw(a0, a1, a2, a3, a3->unk2C0, &sp2C);
    return sp2C;
}
