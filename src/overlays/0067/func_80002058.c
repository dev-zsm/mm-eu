// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_80876228(u8 *, s32);                 /* extern */
M2C_UNK func_808764E4(u8 *, s32);                 /* extern */

void func_80002058(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x304) == 1) {
        func_808764E4(arg0, arg1);
    }
    if (func_80137070(arg0 + 0x144) != 0) {
        func_80876228(arg0, arg1);
    }
}
