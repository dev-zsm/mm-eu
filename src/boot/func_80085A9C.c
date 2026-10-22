// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x8];
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 unkE;
} Struct;

extern void GfxPrint_SetPosPx(Struct *s, s32 a1, s32 a2);

void GfxPrint_SetPos(Struct *s, s32 a1, s32 a2) {
    GfxPrint_SetPosPx(s, a1 << 3, a2 << 3);
}
