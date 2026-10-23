// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Play_GetCamera(u8 *a0, s16 a1) {
    s16 i;
    if (a1 == -1) {
        i = *(s16 *)(a0 + 0x810);
    } else {
        i = a1;
    }
    return *(s32 *)((u8 *)a0 + (i * 4) + 0x800);
}
