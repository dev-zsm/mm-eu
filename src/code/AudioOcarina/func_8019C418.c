// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u32 D_801D0E64;

s32 func_8019C418(void) {
    u8 i = 0;

    // if (1) is needed: dropping the wrapper changes the generated code
    if (1) {
        if (!(D_801D0E64 & 1)) {
            while (1) {
                i++;
                if ((D_801D0E64 >> i) & 1) {
                    break;
                }
                if (i >= 0x18) {
                    break;
                }
            }
        }
        return i;
    }
}
