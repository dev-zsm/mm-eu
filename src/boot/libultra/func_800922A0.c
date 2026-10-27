// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u32 unk4;
} Struct800982B4Inner;

typedef struct {
    u16 unk0;
    u8 pad2[6];
    Struct800982B4Inner *unk8;
    s32 unk0C;
} Struct800982B4;

extern Struct800982B4 *D_800982B4;

s32 __osDisableInt(void);
void __osRestoreInt(s32 a);

void osViSetSpecialFeatures(s32 arg0) {
    s32 temp_a1;

    temp_a1 = __osDisableInt();
    if (arg0 & 1) {
        D_800982B4->unk0C |= 8;
    }
    if (arg0 & 2) {
        D_800982B4->unk0C &= ~8;
    }
    if (arg0 & 4) {
        D_800982B4->unk0C |= 4;
    }
    if (arg0 & 8) {
        D_800982B4->unk0C &= ~4;
    }
    if (arg0 & 0x10) {
        D_800982B4->unk0C |= 0x10;
    }
    if (arg0 & 0x20) {
        D_800982B4->unk0C &= ~0x10;
    }
    if (arg0 & 0x40) {
        D_800982B4->unk0C |= 0x10000;
        D_800982B4->unk0C &= ~0x300;
    }
    if (arg0 & 0x80) {
        D_800982B4->unk0C &= ~0x10000;
        D_800982B4->unk0C |= D_800982B4->unk8->unk4 & 0x300;
    }
    D_800982B4->unk0 |= 8;
    __osRestoreInt(temp_a1);
}
