// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80087010();                                /* extern */
f32 func_800870A0();                                /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80AB3448;

void func_80000350(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x74) = -0.5f;
    M2C_FIELD(arg0, f32 *, 0x68) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) (2.0f * func_800870A0());
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) (2.0f * func_800870A0());
    M2C_FIELD(arg0, s16 *, 0x2FC) = (s16) (func_80087010() & 0xFFF);
    M2C_FIELD(arg0, s16 *, 0x2FE) = (s16) (func_80087010() & 0xFFF);
    M2C_FIELD(arg0, s16 *, 0x300) = (s16) (func_80087010() & 0xFFF);
    M2C_FIELD(arg0, s16 *, 0x302) = 3;
    func_800B8C4C(arg0, 0x28B4);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80AB3448;
}
