// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B5D110(u8 *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80B5D494(u8 *, M2C_UNK, s32, s32);   /* extern */
M2C_UNK func_80B5D784(u8 *, M2C_UNK, M2C_UNK, s32, s32); /* extern */

s32 func_800014A8(u8 *arg0, M2C_UNK arg1) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x358);
    temp_s2 = M2C_FIELD(arg0, s32 *, 0x35C);
    if (!(M2C_FIELD(arg0, s32 *, 0x2F4) & 0x200)) {
        func_80B5D110(arg0, arg1, 0, temp_s1);
    } else {
        func_80B5D494(arg0, arg1, temp_s1, temp_s2);
    }
    if (!(M2C_FIELD(arg0, s32 *, 0x2F4) & 0x400)) {
        func_80B5D110(arg0, arg1, 1, temp_s2);
    } else {
        func_80B5D494(arg0, arg1, temp_s2, temp_s1);
    }
    func_80B5D784(arg0, arg1, 0, temp_s1, temp_s2);
    func_80B5D784(arg0, arg1, 1, temp_s2, temp_s1);
    return 0;
}
