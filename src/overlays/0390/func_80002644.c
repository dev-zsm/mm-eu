// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_6008814;
extern M2C_UNK D_80A9BFEC;
extern M2C_UNK D_80A9E878;

void func_80002644(u8 *arg0) {
    M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) & 0xFFDF);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + 200.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9BFEC;
    M2C_FIELD(arg0, f32 *, 0x68) = -10.0f;
    M2C_FIELD(arg0, f32 *, 0x78) = -10.0f;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A9E878;
    func_80137788(arg0 + 0x148, &D_6008814, 0x3F800000, 0x41200000, (f32) func_80134AE8(&D_6008814), 2, 0.0f);
}
