// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
u32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B74D2C(u8 *, s32);                 /* extern */

void func_80001A74(u8 *arg0, s32 arg1) {
    u32 temp_v0;

    temp_v0 = func_801529DC(arg1 + 0x4908);
    switch (temp_v0) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        break;
    case 5:
        func_80B74D2C(arg0, arg1);
        break;
    }
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x71C, 0xB6);
}
