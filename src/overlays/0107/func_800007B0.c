// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000068;
extern M2C_UNK D_808CC174;

void func_800007B0(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6000068, 0xBF800000, (f32) func_80134AE8(&D_6000068), 0.0f, 2, 0.0f);
    M2C_FIELD(arg0, s16 *, 0x214) = 0x64;
    M2C_FIELD(arg0, s8 *, 0x210) = 0;
    M2C_FIELD(arg0, f32 *, 0x224) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x220) = 0.0f;
    func_800B8C4C(arg0, 0x389E);
    M2C_FIELD(arg0, M2C_UNK **, 0x20C) = &D_808CC174;
}
