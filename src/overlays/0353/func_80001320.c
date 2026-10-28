// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7E28;

s32 func_80001320(void) {
    if (D_801E7E28 & 8) {
        if (D_801E7E28 & 0x10) {
            return 4;
        }
        return 3;
    }
    if (D_801E7E28 & 0x10) {
        return 1;
    }
    return 2;
}
