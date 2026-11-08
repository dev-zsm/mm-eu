// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void Flags_UnsetSwitch(struct PlayState *play, s32 flag) {
    s32 *p;

    if ((flag >= 0) && (flag < 0x80)) {
        p = (s32 *)play + ((flag & ~0x1F) >> 5);
        p[0x1E58 / 4] &= ~(1 << (flag & 0x1F));
    }
}
