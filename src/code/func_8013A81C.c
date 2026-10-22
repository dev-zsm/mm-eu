// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801E6EF0[];

void Snap_UnsetFlag(s32 arg0) {
    if (arg0 < 0x20) {
        *(s32 *)(D_801E6EF0 + 0xE78) &= ~(1 << arg0);
        return;
    }
    arg0 &= 0x1F;
    *(s32 *)(D_801E6EF0 + 0xE7C) &= ~(1 << arg0);
}
