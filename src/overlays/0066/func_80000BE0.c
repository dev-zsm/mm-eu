// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE288(u8 *, s32);                 /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6000590;
extern M2C_UNK D_80874BA4;

void func_80000BE0(u8 *arg0, s32 arg1) {
    func_80137828(arg0 + 0x144, &D_6000590, 0xC0400000);
    if (arg1 != 0) {
        func_800BE288(arg0, arg0 + 0x358);
    }
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x14);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80874BA4;
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 10.0f;
}
