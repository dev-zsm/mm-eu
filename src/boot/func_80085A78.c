// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x8];
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 unkE;
} Struct;

void GfxPrint_SetPosPx(Struct *s, s32 a1, s32 a2) {
    s->unk8 = s->unkC + (a1 << 2);
    s->unkA = s->unkE + (a2 << 2);
}
