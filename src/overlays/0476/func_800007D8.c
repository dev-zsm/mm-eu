// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60001A8;
extern M2C_UNK D_80B11C58;

void func_800007D8(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60001A8, 0xC0C00000, arg0);
    M2C_FIELD(arg0, s16 *, 0x18E) = 0xC;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x38EC);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B11C58;
}
