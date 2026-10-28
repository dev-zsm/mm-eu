// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000360(s32 arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 6) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF42) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF42) | 0x40);
        func_800B6490(arg0);
    }
}
