// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B30160();                            /* extern */
extern M2C_UNK D_80B307B4;
extern M2C_UNK D_80B33390;
extern s32 D_80B33670;

void func_80008080(u8 *arg0, M2C_UNK arg1) {
    if (D_80B33670 == 2) {
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B307B4;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B33390;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        func_80B30160();
    }
}
