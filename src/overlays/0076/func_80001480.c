// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(s32, s16, M2C_UNK);               /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_8089A0D0(u8 *, s32);                 /* extern */

void func_80001480(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x28C), 0x400) != 0) {
        func_8089A0D0(arg0, arg1);
    }
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
