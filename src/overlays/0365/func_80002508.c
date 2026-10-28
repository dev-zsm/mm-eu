// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A5D47C(u8 *, s32);                 /* extern */

void func_80002508(u8 *arg0, s32 arg1) {
    f32 sp2C;

    sp2C = M2C_FIELD(arg0, f32 *, 0x15C);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0xBB8, 0x14);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x374) <= sp2C) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        M2C_FIELD(arg0, s16 *, 0x30) = 0;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        M2C_FIELD(arg0, s16 *, 0x28E) = func_800FF250(0xA, 0xA);
        func_80A5D47C(arg0, arg1);
    }
}
