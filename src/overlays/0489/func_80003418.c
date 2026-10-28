// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B2A01C(s32, s32);                    /* extern */
M2C_UNK func_80B2A1EC(s32, s32);                    /* extern */
M2C_UNK func_80B2BB50(s32);                         /* extern */
extern u16 D_801E6EFC;

void func_80003418(s32 arg0, s32 arg1) {
    if (((s32) D_801E6EFC < 0x4000) && ((s32) D_801E6EFC >= 0x1AAA)) {
        func_80B2A1EC(arg0, arg1);
        func_80B2A01C(arg0, arg1);
        func_80B2BB50(arg0);
    }
}
