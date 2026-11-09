// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(s32, s32);                    /* extern */
M2C_UNK func_80181278(s32);                         /* extern */
M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_80BC4E10;

void func_800017B0(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    switch (arg1) {
    case 3:
        func_80181278(arg4 + 0x190);
        return;
    case 11:
        func_80181278(arg4 + 0x1D0);
        return;
    case 12:
        func_80181278(arg4 + 0x210);
        return;
    case 13:
        func_80181278(arg4 + 0x250);
        return;
    case 14:
        func_80181278(arg4 + 0x290);
        return;
    case 15:
        func_80181278(arg4 + 0x2D0);
        return;
    case 16:
        func_80182B28(&D_80BC4E10, arg4 + 0x3C);
        func_800FF32C(arg4 + 0x48, arg4 + 0x30);
        /* fallthrough */
    default:
        return;
    }
}
