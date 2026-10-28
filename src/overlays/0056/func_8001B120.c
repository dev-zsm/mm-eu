// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80124578(u8 *);                          /* extern */
s32 func_80830238(s32, u8 *);                     /* extern */
s32 func_80830744(u8 *, s32);                     /* extern */
s32 func_808307D4(s32, u8 *);                     /* extern */

s32 func_8001B120(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xB28);
    if (temp_v0 >= 0) {
        M2C_FIELD(arg0, s16 *, 0xB28) = (s16) -temp_v0;
    }
    if (((func_80124578(arg0) == 0) || (func_808307D4(arg1, arg0) != 0)) && (func_80830238(arg1, arg0) == 0) && (func_80830744(arg0, arg1) == 0)) {
        return 0;
    }
    return 1;
}
