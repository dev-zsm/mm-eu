// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
s32 func_80ACE87C(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK D_80ACECA0;
extern M2C_UNK D_80AD05D4;
extern M2C_UNK D_80AD0A80;

void func_80001E08(u8 *arg0) {
    if (func_80ACE87C(0, 4) == 0) {
        func_80ACE87C(1, 4);
        M2C_FIELD(arg0, s16 *, 0x356) = 1;
    }
    if (&D_80ACECA0 == M2C_FIELD(arg0, M2C_UNK **, 0x1D4)) {
        func_800BD9E0(arg0 + 0x190, &D_80AD0A80, 0xF);
    }
    M2C_FIELD(arg0, s16 *, 0x354) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AD05D4;
}
