// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80124764(u8 *);                          /* extern */
M2C_UNK func_8082D314(s32, u8 *);                 /* extern */
M2C_UNK func_80834A8C(s32, u8 *);                 /* extern */
s32 func_808388B0(u8 *, s32);                     /* extern */
M2C_UNK func_808395A8(u8 *, s32);                 /* extern */
M2C_UNK func_8083C914(u8 *, s32);                 /* extern */

void func_8002D080(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    if (func_80124764(arg1) != 0) {
        func_80834A8C(arg0, arg1);
        func_8082D314(arg0, arg1);
    } else {
        func_808395A8(arg1, arg0);
        if (func_808388B0(arg1, arg0) == 0) {
            func_8083C914(arg1, arg0);
        }
    }
    M2C_FIELD(arg1, s8 *, 0x394) = 0;
    M2C_FIELD(arg1, s8 *, 0xAA5) = 0;
}
