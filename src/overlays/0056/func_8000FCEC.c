// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_8085DB6C;

s32 func_8000FCEC(u8 *arg0, u8 *arg1) {
    if ((arg1 != NULL) && !(M2C_FIELD(arg1, s32 *, 4) & 0x800000) && ((M2C_FIELD(arg0, f32 *, 0xAD0) < D_8085DB6C) || (M2C_FIELD(arg1, s16 *, 0) == 0x6A))) {
        return 0;
    }
    return 1;
}
