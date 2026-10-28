// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800F1944(s16);                         /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_80A7283C;

void func_800028BC(u8 *arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 6) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A7283C;
        if (M2C_FIELD(arg0, s16 *, 0x334) == 0) {
            if (func_800F1E2C() == 0x7C) {
                func_800F1D6C(0x7C);
            }
            M2C_FIELD(arg0, s16 *, 0x3E0) = (s16) M2C_FIELD(arg0, s16 *, 0x410);
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x3E0));
        }
        func_800B8364(arg0, arg1, 0x43C80000, -1);
    }
}
