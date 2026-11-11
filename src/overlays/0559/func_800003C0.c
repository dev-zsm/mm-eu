#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1B24(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80BAA12C(u8 *);                      /* extern */

void func_800003C0(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(((s16 *)(arg0 + 0x324))[M2C_FIELD(arg0, s32 *, 0x290)]) != 0) {
        func_800F1B24(((s16 *)(arg0 + 0x324))[M2C_FIELD(arg0, s32 *, 0x290)], arg0);
        func_80BAA12C(arg0);
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
    }
    func_800F1944(((s16 *)(arg0 + 0x324))[M2C_FIELD(arg0, s32 *, 0x290)]);
}
