// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, s16);        /* extern */
M2C_UNK func_80A02BB4(u8 *);                      /* extern */
s32 func_80A03008(u8 *, s32, M2C_UNK);            /* extern */
s32 func_80A03404(u8 *, s32);                     /* extern */
M2C_UNK func_80A03740(u8 *);                      /* extern */

void func_800011E8(u8 *arg0, s32 arg1) {
    s32 sp24;

    sp24 = 1;
    func_800FEC70(arg0 + 0x4DA, 0, M2C_FIELD(arg0, s16 *, 0x4DE));
    if ((func_80A03008(arg0, arg1, 0) != 0) && (func_80A03404(arg0, arg1) != 0)) {
        sp24 = 0;
    }
    if (sp24 != 0) {
        func_80A02BB4(arg0);
        func_80A03740(arg0);
    }
}
