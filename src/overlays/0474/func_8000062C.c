// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C57F4(s32, s32, s32, u8 *);           /* extern */

s32 func_8000062C(u8 *arg0, s32 arg1) {
    if (func_800C57F4(arg1 + 0x830, arg0 + 0x2F4, M2C_FIELD(arg0, s32 *, 0x33C), arg0) != 0) {
        return 1;
    }
    return 0;
}
