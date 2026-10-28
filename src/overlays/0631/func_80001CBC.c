// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000C50;
extern M2C_UNK D_80BF1D7C;

void func_80001CBC(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s32 *, 0x2A4) = 0;
    func_80137788(arg0 + 0x144, &D_6000C50, 0xBF800000, M2C_FIELD(arg0, f32 *, 0x15C) - 1.0f, 0.0f, 2, 0.0f);
    M2C_FIELD(arg0, s16 *, 0x294) = 0xA;
    func_800B8C4C(arg0, 0x3AA3);
    M2C_FIELD(arg0, s16 *, 0x2B4) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BF1D7C;
}
