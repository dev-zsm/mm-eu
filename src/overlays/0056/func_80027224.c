// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136480(s32, s32);                    /* extern */
M2C_UNK func_808325D4(u8 *);                      /* extern */
M2C_UNK func_80836038(u8 *, s32);                 /* extern */

void func_80027224(u8 *arg0, s32 arg1) {
    func_80136480(arg1, arg0 + 0x240);
    func_808325D4(arg0);
    if (M2C_FIELD(arg0, f32 *, 0x258) >= 6.0f) {
        func_80836038(arg0, arg1);
    }
}
