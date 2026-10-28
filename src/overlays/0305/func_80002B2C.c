// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A083C0(u8 *);                      /* extern */
s32 func_80A08CC0(u8 *, s32);                     /* extern */
M2C_UNK func_80A0964C(u8 *);                      /* extern */
s32 func_80A09684(u8 *, s32);                     /* extern */
s32 func_80A09F68(u8 *);                          /* extern */
M2C_UNK func_80A0A14C(u8 *, s32);                 /* extern */

void func_80002B2C(u8 *arg0, s32 arg1) {
    if (func_80A09F68(arg0) != -1) {
        func_80A0A14C(arg0, arg1);
    }
    func_80A083C0(arg0);
    if (func_80A08CC0(arg0, arg1) != 0) {
        func_800B8C4C(arg0, 0x2835);
    }
    if (func_80A09684(arg0, arg1) != 0) {
        func_80A0964C(arg0);
        if (M2C_FIELD(arg0, s8 *, 0x2B0) == 3) {
            func_800B8C4C(arg0, 0x28C5);
        }
    }
}
