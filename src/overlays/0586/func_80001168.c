// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013B284(s32, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80BC301C(u8 *, M2C_UNK);             /* extern */

s32 func_80001168(u8 *arg0, M2C_UNK arg1, u8 *arg2) {
    u8 temp_v0;

    func_8013B284(arg0 + 0x4C2, 3, 7, arg0);
    temp_v0 = *arg2;
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_80BC301C(arg0, 0);
        break;
    case 2:
        M2C_FIELD(arg0, s32 *, 0x4F0) = 0;
        M2C_FIELD(arg0, s16 *, 0x4EA) = 0;
        func_80BC301C(arg0, 2);
        break;
    }
    return 1;
}
