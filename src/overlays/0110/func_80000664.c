// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8013796C(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60041F4;
extern M2C_UNK D_808D0440;
extern M2C_UNK D_808D0650;

void func_80000664(u8 *arg0) {
    if (&D_808D0650 != M2C_FIELD(arg0, M2C_UNK **, 0x188)) {
        func_8013796C(arg0 + 0x144, &D_60041F4, 0x3FC00000, arg0);
    } else {
        M2C_FIELD(arg0, f32 *, 0x160) = 1.5f;
    }
    M2C_FIELD(arg0, s16 *, 0x18E) = func_800FF250(2, 4);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D0440;
    M2C_FIELD(arg0, f32 *, 0x70) = 1.5f;
}
