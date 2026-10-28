// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
M2C_UNK func_80151E7C(s32, s32);                    /* extern */
M2C_UNK func_809F15DC(u8 *, M2C_UNK *);           /* extern */
s16 func_809F1668(u8 *, s32);                     /* extern */
extern M2C_UNK D_809F278C;

void func_80000B10(s32 arg0, u8 *arg1) {
    s16 temp_v0;

    func_809F15DC(arg1, &D_809F278C);
    temp_v0 = func_809F1668(arg1, arg0);
    M2C_FIELD(arg1, s16 *, 0x3B6) = temp_v0;
    func_80151E7C(arg0, temp_v0 & 0xFFFF);
    func_80115540(arg0, 6);
    M2C_FIELD(arg1, s32 *, 0x358) = 0;
    M2C_FIELD(arg1, s32 *, 0x390) = 0;
}
