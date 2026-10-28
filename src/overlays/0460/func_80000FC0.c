// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800C604C(s32, s32, s32);               /* extern */
M2C_UNK func_80AF77B8(u8 *);                      /* extern */
M2C_UNK func_80AF8708(u8 *);                      /* extern */
extern M2C_UNK D_80AF8938;

void func_80000FC0(u8 *arg0, s32 arg1) {
    s32 pad;
    s32 sp20;

    sp20 = 0;
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) != 0) {
        sp20 = 1;
        func_800B8C4C(arg0, 0x283E);
    }
    if (sp20 != 0) {
        func_80AF77B8(arg0);
        func_800C604C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AF8938;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x20);
        func_80AF8708(arg0);
    }
}
