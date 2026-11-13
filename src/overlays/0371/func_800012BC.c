#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151E7C(s32, s32);                    /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
s32 func_80A7048C(s32);                             /* extern */
s32 func_80A707BC(u8 *);                          /* extern */
s32 func_80A7090C(u8 *, s32);                     /* extern */
extern M2C_UNK D_80A71B68;

s32 func_800012BC(s32 arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = ((u8 **)(arg1 + 0x340))[M2C_FIELD(arg1, u8 *, 0x34C)];
    if (func_80A7090C(arg1, arg0) != 0) {
        return 1;
    }
    if (func_80A7048C(arg0) != 0) {
        if ((M2C_FIELD(sp24, s16 *, 0x1C) != 2) || (M2C_FIELD(arg1, u16 *, 0x42C) & 2)) {
            M2C_FIELD(arg1, M2C_UNK **, 0x148) = (M2C_UNK *) M2C_FIELD(arg1, M2C_UNK **, 0x144);
            func_80151E7C(arg0, func_80A707BC(arg1) & 0xFFFF);
            func_8019FF78(0x4808);
            M2C_FIELD(arg1, s32 *, 0x384) = 0;
            M2C_FIELD(arg1, s32 *, 0x3BC) = 0;
            M2C_FIELD(arg1, s8 *, 0x400) = 0;
            M2C_FIELD(arg1, M2C_UNK **, 0x144) = &D_80A71B68;
            return 1;
        }
        func_8019FF78(0x4806);
        return 1;
    }
    return 0;
}
