// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_80895428;

void func_800024C0(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 1.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x2BC) = func_800FF250(0x14, 0x14, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_80895428;
}
