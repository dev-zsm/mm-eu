// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(s32, s32);                    /* extern */
M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
M2C_UNK func_80B38E54(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_80B3DC04;

void func_800046A8(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 9) {
        func_80182B28(&D_80B3DC04, arg4 + 0x3C);
        func_800FF32C(arg4 + 0x48, arg4 + 0x30);
        func_80B38E54(arg4, arg0, 1);
        return;
    }
    if (arg1 == 8) {
        func_80B38E54(arg4, arg0, 0);
        func_80B38E54(arg4, arg0, 4);
        func_80B38E54(arg4, arg0, 2);
        func_80B38E54(arg4, arg0, 3);
        return;
    }
    if (arg1 == 5) {
        func_80B38E54(arg4, arg0, 5);
    }
}
