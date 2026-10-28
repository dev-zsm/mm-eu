// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_809936F0(u8 *, s32);                 /* extern */
extern s32 D_80995C80;

void func_80001F14(u8 *arg0, s32 arg1) {
    f32 sp2C;

    sp2C = M2C_FIELD(arg0, f32 *, 0x15C);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0xBB8, 0x14);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x288) == 0) || ((M2C_FIELD(arg0, f32 *, 0x350) <= sp2C) && (M2C_FIELD(arg0, u16 *, 0x90) & 1))) {
        M2C_FIELD(arg0, s16 *, 0x30) = 0;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, s16 *, 0x288) = 0;
        D_80995C80 = 0;
        M2C_FIELD(arg0, s16 *, 0x28E) = 0;
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        M2C_FIELD(arg0, s16 *, 0x286) = func_800FF250(0xA, 0xA);
        func_809936F0(arg0, arg1);
    }
}
