// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x18E];
    u8 f;
} T0068;

extern f32 D_8087AC58;

s32 func_80001858(u8 *play, s32 limbIndex, s32 *dList, f32 *pos, s32 rot, T0068 *thisx) {
    if (thisx->f != 0 && *(s8 *)(play + 0x1CA4) != 0x64) {
        *dList = 0;
    } else if (limbIndex == 1) {
        pos[1] += D_8087AC58;
    }
    return 0;
}
