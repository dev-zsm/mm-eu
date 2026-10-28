// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5B64(s32, s32);                    /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_8091CAA0(u8 *);                      /* extern */
M2C_UNK func_8091CE2C(u8 *);                      /* extern */

void func_800015A8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x1E8)(arg0);
    if (M2C_FIELD(arg0, s8 *, 0x1E0) >= 3) {
        M2C_FIELD(arg0, s32 *, 0x1E4) = 3;
        func_800B5B64(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F);
        M2C_FIELD(arg0, s32 *, 0x1E4) = 5;
        func_8091CE2C(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x1E4) == 4) {
        func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
        func_8019FF78(0x4806);
        M2C_FIELD(arg0, s32 *, 0x1E4) = 0;
        func_8091CAA0(arg0);
    }
}
