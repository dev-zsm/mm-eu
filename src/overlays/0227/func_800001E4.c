// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5B64(u8 *, s16);                 /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E0108(s32);                         /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
s32 func_800F1984(s8);                              /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
M2C_UNK func_800F1B24(s8, u8 *);                  /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
s8 func_800F1E68(s8);                               /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
M2C_UNK func_80968374(u8 *);                      /* extern */

void func_800001E4(u8 *arg0, u8 *arg1) {
    s16 temp_a1;

    if ((M2C_FIELD(arg0, s32 *, 0x148) == 1) && (func_800F1E2C() == 0x7D)) {
        func_800F1D6C(0x7D);
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
        return;
    }
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38)) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x148) == 1) {
            func_800F1B24(M2C_FIELD(arg0, s8 *, 0x38), arg0);
            func_800E0108(M2C_FIELD(arg1, s32 *, 0x800));
        } else {
            func_800F1A08(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        }
        if (M2C_FIELD(arg1, s16 *, 0xA4) == 0x1D) {
            func_801A9868(0x806F);
        }
        M2C_FIELD(arg0, s8 *, 0x38) = func_800F1E68(M2C_FIELD(arg0, s8 *, 0x38));
        if (M2C_FIELD(arg0, s8 *, 0x38) == -1) {
            temp_a1 = M2C_FIELD(arg0, s16 *, 0x1C);
            if (temp_a1 != 0xFF) {
                func_800B5B64(arg1, temp_a1);
            }
            func_800B6490(arg0);
        }
    } else {
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
        func_80968374(arg1);
    }
}
