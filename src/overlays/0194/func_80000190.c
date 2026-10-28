// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5B64(s32, s32);                    /* extern */
M2C_UNK func_800B5C4C(s32, s8);                     /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
s32 func_800F1984(s8);                              /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
s32 func_800F1EA8(s8);                              /* extern */

void func_80000190(u8 *arg0, s32 arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38)) != 0) {
        func_800B5C4C(arg1, M2C_FIELD(arg0, s8 *, 3));
        func_800B5B64(arg1, M2C_FIELD(arg0, s32 *, 0x148));
        if (func_800F1EA8(M2C_FIELD(arg0, s8 *, 0x38)) != -1) {
            func_800F1A08(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        }
        func_800B6490(arg0);
        return;
    }
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
}
