// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK D_80A42C14;
extern M2C_UNK D_80A437A8;

void func_80002CB8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80A42C14;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A437A8;
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    M2C_FIELD(arg0, s8 *, 0x1D0) = (s8) (s32) (func_8008704C() * 3.0f);
    M2C_FIELD(arg0, s8 *, 0x1D1) = (s8) ((s32) (func_8008704C() * 8.0f) + 7);
    M2C_FIELD(arg0, s16 *, 0x1CA) = func_800FF250(0x13, 2);
}
