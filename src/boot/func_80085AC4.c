// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
    u8 unkE;
} Struct;

void GfxPrint_SetBasePosPx(Struct *s, s32 a1, s32 a2) {
    s->unkC = a1 << 2;
    s->unkE = a2 << 2;
}
