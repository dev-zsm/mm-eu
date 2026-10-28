// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7E1F;

s32 func_80000148(s32 arg0, M2C_UNK arg1) {
    if (D_801E7E1F & 0x80) {
        return 0;
    }
    return 1;
}
