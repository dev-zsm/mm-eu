#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0088.h"

M2C_UNK func_80151E7C(s32, u16);                    /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_808A77C0(u8 *, M2C_UNK *);           /* extern */
s32 func_808A77CC(s32);                             /* extern */
s32 func_808A7D1C(u8 *, s32);                     /* extern */
extern M2C_UNK D_808A97E8;

s32 func_8000176C(s32 arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = ((u8 **)(arg1 + 0x1E8))[M2C_FIELD(arg1, u8 *, 0x236)];
    if (func_808A7D1C(arg1, arg0) != 0) {
        return 1;
    }
    if (func_808A77CC(arg0) != 0) {
        if (M2C_FIELD(sp24, s16 *, 0x1A0) == 0) {
            M2C_FIELD(arg1, s32 *, 0x18C) = (s32) M2C_FIELD(arg1, s32 *, 0x188);
            func_80151E7C(arg0, M2C_FIELD(((u8 **)(arg1 + 0x1E8))[M2C_FIELD(arg1, u8 *, 0x236)], u16 *, 0x198));
            M2C_FIELD(arg1, s32 *, 0x26C) = 0;
            M2C_FIELD(arg1, s32 *, 0x2A4) = 0;
            func_8019FF78(0x4808);
            M2C_FIELD(arg1, s8 *, 0x235) = 0;
            func_808A77C0(arg1, &D_808A97E8);
            return 1;
        }
        func_8019FF78(0x4806);
        return 1;
    }
    return 0;
}
