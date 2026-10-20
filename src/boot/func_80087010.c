// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u32 D_800976D0;

u32 func_80087010(void) {
    return D_800976D0 = D_800976D0 * 0x19660D + 0x3C6EF35F;
}
