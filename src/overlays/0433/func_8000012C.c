// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000012C(s32 arg0, u8 *arg1) {
    return M2C_FIELD(arg1, s32 *, 0x1CCC);
}
