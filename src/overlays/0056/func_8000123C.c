// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000123C(u8 *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xA6C) & 0x01000000;
}
