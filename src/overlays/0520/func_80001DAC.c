// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8);                          /* extern */
s32 func_800F1984(s8);                              /* extern */
M2C_UNK func_800F1B24(s8, u8 *);                  /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80B75060(u8 *);                      /* extern */

void func_80001DAC(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38)) != 0) {
        func_800F1B24(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        func_80B75060(arg0);
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
    }
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
}
