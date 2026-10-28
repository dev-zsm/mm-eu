// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AB814C(u8 *, s32);                 /* extern */
M2C_UNK func_80AB987C(u8 *, s32);                 /* extern */
M2C_UNK func_80AB99FC(u8 *, s32);                 /* extern */
M2C_UNK func_80AB9F64(u8 *, s32);                 /* extern */

void func_80001DD0(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3B2);
    if ((temp_v0 != 6) && (temp_v0 != 0xA) && (temp_v0 != 0xD) && (temp_v0 != 0xE) && (temp_v0 != 0x10) && (temp_v0 != 8) && (temp_v0 != 9)) {
        func_80AB987C(arg0, arg1);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x144)(arg0, arg1);
    func_80AB814C(arg0, arg1);
    func_80AB9F64(arg0, arg1);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x3B2);
    if ((temp_v0_2 != 6) && (temp_v0_2 != 0xA) && (temp_v0_2 != 0xD) && (temp_v0_2 != 0xE) && (temp_v0_2 != 0x10) && (temp_v0_2 != 8) && (temp_v0_2 != 9)) {
        func_80AB99FC(arg0, arg1);
    }
}
