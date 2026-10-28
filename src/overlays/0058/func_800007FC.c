// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s16 D_801E6F2A;

s32 func_800007FC(u8 *arg0, M2C_UNK arg1) {
    if (D_801E6F2A < M2C_FIELD(arg0, s32 *, 0x16978)) {
        return 4;
    }
    return 0;
}
