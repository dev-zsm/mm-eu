// FLAGS: -O2 -g3 -mips2
#include "types.h"
s64 func_800905C0(s32);
void PadMgr_GetInputNoLock(u16 *, s32);
extern s32 D_801C065C;
extern u8 D_801E6EF0[];
extern u16 D_801ED0D0;

void func_8010E808(s32 arg0) {
    s32 temp_a0;

    PadMgr_GetInputNoLock(&D_801ED0D0, 0);
    temp_a0 = ~(D_801ED0D0 | 0xFFFF7FFF) == 0;
    if ((temp_a0 != D_801C065C) && (temp_a0 != 0)) {
        *(s64 *)(D_801E6EF0 + 0x3DC8) = func_800905C0(temp_a0);
        *(s8 *)(D_801E6EF0 + 0x3DD0) = 0xF;
    }
    D_801C065C = temp_a0;
}
