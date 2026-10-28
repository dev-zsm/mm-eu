// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_800BBED8(s32, s32, u8 *, M2C_UNK);   /* extern */
extern M2C_UNK D_80918250;

void func_80001230(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xBD6) = 0;
    M2C_FIELD(arg0, f32 *, 0xBBC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s8 *, 0xBCC) = 1;
    M2C_FIELD(arg0, s8 *, 0xBCE) = 0;
    M2C_FIELD(arg0, s8 *, 0xBD8) = 1;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s8 *, 0xBD7) = 0;
    M2C_FIELD(arg0, s16 *, 0xBCA) = 0x3C;
    func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 6);
    func_800A8248(arg1, arg0, arg0 + 0x24, 0xA0);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80918250;
}
