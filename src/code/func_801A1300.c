// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4ACD;
extern u8 D_801F4ACF;

void Audio_LowerMainBgmVolume(u8 arg0) {
    D_801F4ACD = arg0;
    D_801F4ACF = 1;
}
