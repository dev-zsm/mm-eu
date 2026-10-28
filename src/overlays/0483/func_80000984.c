// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
extern M2C_UNK D_80B1FB90;

void func_80000984(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x2E4)) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x2E4), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B1FB90;
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x2E4));
}
