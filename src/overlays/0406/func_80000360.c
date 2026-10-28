// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 func_80000360(u8 *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13);
}
