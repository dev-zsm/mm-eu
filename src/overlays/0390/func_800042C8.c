// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A99DE0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80A9DC24;

void func_800042C8(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    func_80137070(arg0 + 0x148);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9DC24;
        func_80A99DE0(arg0, 7);
        return;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0)) {
        func_800B8398(arg0, arg1, 0x42DC0000);
    }
}
