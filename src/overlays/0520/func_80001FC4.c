// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(u8 *, s32, M2C_UNK);        /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B752BC(s32);                         /* extern */

void func_80001FC4(s32 arg0, u8 *arg1) {
    s32 temp_s0;

    temp_s0 = arg1 + 0x4908;
    if (((func_801529DC(temp_s0) == 6) || (func_801529DC(temp_s0) == 5)) && (func_80147B34(arg1) != 0) && (func_801529DC(temp_s0) == 5)) {
        func_800B701C(arg1, arg0, 7);
        func_80147CC4(arg1);
    }
    if ((func_801529DC(temp_s0) == 0) && (M2C_FIELD(arg1, u8 *, 0x169BD) == 0)) {
        func_80B752BC(arg0);
    }
}
