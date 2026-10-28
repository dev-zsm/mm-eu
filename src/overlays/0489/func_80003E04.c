// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B28B04(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B29014(u8 *);                      /* extern */
M2C_UNK func_80B294F0(u8 *, s32);                 /* extern */
extern f32 D_80B33BC4;

void func_80003E04(u8 *arg0, s32 arg1) {
    func_80B29014(arg0);
    func_80B294F0(arg0, arg1);
    func_80B28B04(arg0, 0x320, 0);
    func_800B8D94(arg0, 0x320A);
    if (D_80B33BC4 <= M2C_FIELD(arg0, f32 *, 0x320)) {
        M2C_FIELD(arg0, s8 *, 0x38A) = 1;
    }
}
