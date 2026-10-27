// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801F4C7A;
extern s32 D_801CF91C;
void *AudioOcarina_GetPlayingStaff(void) {
    if (*(u8 *)((u8 *)&D_801F4C7A + 1) < 0xFE) {
        D_801CF91C = 0;
    }
    return &D_801F4C7A;
}
