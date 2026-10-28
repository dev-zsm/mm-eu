// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B28B04(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B29014(u8 *);                      /* extern */
M2C_UNK func_80B294F0(u8 *, s32);                 /* extern */
M2C_UNK func_80B29E9C(u8 *);                      /* extern */
M2C_UNK func_80B2AE48(u8 *);                      /* extern */
M2C_UNK func_80B2C298(u8 *);                      /* extern */

void func_80003B2C(u8 *arg0, s32 arg1) {
    func_80B29014(arg0);
    func_80B294F0(arg0, arg1);
    func_80B28B04(arg0, 0x320, 0);
    if (M2C_FIELD(arg0, f32 *, 0x320) > 0.0f) {
        func_800B6564(arg0, 0x3C23D70A);
        func_80B29E9C(arg0);
        func_80B2AE48(arg0 + 0x24);
        func_80B2C298(arg0);
    }
}
