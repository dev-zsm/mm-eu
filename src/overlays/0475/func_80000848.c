// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_8013CD14(u8 *, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80B10560(u8 *, s32);                 /* extern */
M2C_UNK func_80B1092C(u8 *, s32);                 /* extern */

void func_80000848(u8 *arg0, s32 arg1) {
    func_80B1092C(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x188)(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x1D8) != 0) {
        if (func_800B7164(arg0, 0x1FFE) != 0) {
            M2C_FIELD(arg0, s32 *, 0x214) = 0;
            func_8013CD14(arg0, arg1, 0x42700000, 0x41A00000, 0, M2C_FIELD(arg0, u16 *, 0x208) & 7);
        }
        func_800B64E0(arg0, 0x41A00000);
        func_80B10560(arg0, arg1);
    }
}
