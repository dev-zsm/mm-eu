// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8082EBD4(u8 *);                          /* extern */

s32 func_800021E8(u8 *arg0, s32 arg1) {
    if ((arg1 < 0xFD) && (func_8082EBD4(arg0) == M2C_FIELD(arg0, s8 *, 0x14A))) {
        return 1;
    }
    return 0;
}
