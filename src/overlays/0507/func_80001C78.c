#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0507.h"

M2C_UNK func_80181A3C();                /* extern */
M2C_UNK func_80182B28();      /* extern */
extern M2C_UNK D_80B5A6E4;
extern M2C_UNK D_80B5A6F0;
extern M2C_UNK D_80B5A6FC;
extern M2C_UNK D_80B5A708;

void func_80001C78(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    if (arg1 == 0x15) {
        func_80182B28(&D_80B5A6E4, arg4 + 0x3C, arg1);
    }
    if (arg1 == 0x16) {
        func_80182B28(&D_80B5A6F0, arg4 + 0x3A4, arg1);
        func_80181A3C(M2C_FIELD(arg4, s16 *, 0xBE), 0);
        func_80182B28(&D_80B5A6FC, arg4 + 0x3B0);
        func_80182B28(&D_80B5A708, arg4 + 0x3BC);
    }
}
