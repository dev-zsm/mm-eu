// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0645.h"

M2C_UNK func_80181278(s32);                         /* extern */

void func_800002D4(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    switch (arg1) {
    case 3:
        func_80181278(arg4 + 0x18C);
        return;
    case 11:
        func_80181278(arg4 + 0x1CC);
        return;
    case 12:
        func_80181278(arg4 + 0x20C);
        return;
    case 13:
        func_80181278(arg4 + 0x24C);
        return;
    case 14:
        func_80181278(arg4 + 0x28C);
        return;
    case 15:
        func_80181278(arg4 + 0x2CC);
        /* fallthrough */
    default:
        return;
    }
}
