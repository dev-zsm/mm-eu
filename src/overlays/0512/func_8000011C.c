// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000011C(u8 *arg0, M2C_UNK arg1) {
    return M2C_FIELD(arg0, s8 *, 0x17B) >= 0xB;
}
