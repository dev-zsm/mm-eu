// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6FD0(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6009520;
extern M2C_UNK D_80874E3C;

void func_80000E9C(u8 *arg0, s32 arg1) {
    func_80137828(arg0 + 0x144, &D_6009520, 0xC0A00000, arg0);
    M2C_FIELD(arg0, s16 *, 0x18E) = -0x1E;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80874E3C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2C0) = (f32) M2C_FIELD(arg0, f32 *, 0x9C);
    func_800B6FD0(arg1, arg0, 0x12);
}
