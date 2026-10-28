// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32, u8 *);                     /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_808F3714(s32, u8 *, s32, u16);       /* extern */
s32 func_808F3AD4(s32, u8 *, s32);                /* extern */

s32 func_800025C4(s32 arg0, u8 *arg1, s32 arg2) {
    s32 pad;
    s32 sp20;
    s32 temp_v0;

    sp20 = 0;
    temp_v0 = func_801529DC(arg0 + 0x4908);
    switch (temp_v0) {                              /* irregular */
    case 2:
        func_808F3714(arg0, arg1, arg2, M2C_FIELD(arg1, u16 *, 0x116));
        sp20 = 1;
        break;
    case 4:
    case 5:
        if ((func_80147B34(arg0, arg1) != 0) && (func_808F3AD4(arg0, arg1, arg2) != 0)) {
            func_80147CC4(arg0);
            sp20 = 1;
        }
        break;
    }
    return sp20;
}
