// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A2141C(u8 *);                      /* extern */
s32 func_80A21450(u8 *);                          /* extern */
s32 func_80A218E4(u8 *, s32, M2C_UNK);            /* extern */
s32 func_80A21940(u8 *, s32);                     /* extern */
M2C_UNK func_80A21C60(u8 *);                      /* extern */
M2C_UNK func_80A21E38(u8 *);                      /* extern */

void func_80000B58(u8 *arg0, s32 arg1) {
    s32 sp24;

    sp24 = func_80A21450(arg0);
    if (func_80A218E4(arg0, arg1, 1) != 0) {
        M2C_FIELD(arg0, s16 *, 0x3C4) = 0x7D0;
        if (func_80A21940(arg0, arg1) != 0) {
            func_80A21E38(arg0);
            return;
        }
        func_80A2141C(arg0);
        func_80A21C60(arg0);
        return;
    }
    if (sp24 != 0) {
        func_80A2141C(arg0);
        M2C_FIELD(arg0, s16 *, 0x3C4) = 0x78;
        func_80A21C60(arg0);
    }
}
