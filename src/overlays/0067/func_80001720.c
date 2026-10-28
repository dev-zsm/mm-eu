// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_80876AE4(u8 *);                      /* extern */

void func_80001720(u8 *arg0, M2C_UNK arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_80876AE4(arg0);
        M2C_FIELD(arg0, s16 *, 0x302) = func_800FF250(0xA, 0x14);
    }
}
