// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, u8 *, u8 *, M2C_UNK); /* extern */
extern M2C_UNK D_80B009D0;

void func_8000189C(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x192) = 0;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0x230);
    func_800A8248(arg1, arg0, arg0 + 0x24, 0x80);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B009D0;
}
