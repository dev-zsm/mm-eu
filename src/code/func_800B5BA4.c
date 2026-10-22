// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Flags_UnsetSwitch(s32 *arg0, s32 arg1) {
    s32 *p;

    if ((arg1 >= 0) && (arg1 < 0x80)) {
        p = (s32 *)arg0 + ((arg1 & ~0x1F) >> 5);
        p[0x1E58 / 4] &= ~(1 << (arg1 & 0x1F));
    }
}
