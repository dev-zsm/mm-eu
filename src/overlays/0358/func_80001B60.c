// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_80A4F0CC;

void func_80001B60(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x368) = 0x64;
    M2C_FIELD(arg0, f32 *, 0x74) = -0.25f;
    M2C_FIELD(arg0, f32 *, 0x78) = -3.5f;
    M2C_FIELD(arg0, s16 *, 0x370) = func_800FF250(-0x3E8, 0x7D0, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80A4F0CC;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.5f;
}
