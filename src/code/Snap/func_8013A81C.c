// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801E6EF0[];

void Snap_UnsetFlag(s32 flag) {
    if (flag < 0x20) {
        *(s32 *)(D_801E6EF0 + 0xE78) &= ~(1 << flag);
        return;
    }
    flag &= 0x1F;
    *(s32 *)(D_801E6EF0 + 0xE7C) &= ~(1 << flag);
}
