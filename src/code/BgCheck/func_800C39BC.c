// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 BgCheck_GetCollisionHeader(u8 *arg0, s32 arg1) {
    if (arg1 == 0x32) {
        return *(s32 *)arg0;
    }
    if ((arg1 < 0) || (arg1 >= 0x33)) {
        return 0;
    }
    if (!(*(u16 *)((s32)arg0 + (arg1 * 2) + 0x13DC) & 1)) {
        return 0;
    }
    return *(s32 *)((s32)arg0 + (arg1 * 0x64) + 0x58);
}
