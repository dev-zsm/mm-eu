#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0293.h"

M2C_UNK func_80151E7C(s32, u16);                    /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_809F15DC(u8 *, M2C_UNK *);           /* extern */
s32 func_809F15E8(s32);                             /* extern */
s32 func_809F1EB8(u8 *, s32);                     /* extern */
extern M2C_UNK D_809F35B4;

s32 func_80001A48(s32 arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = ((u8 **)(arg1 + 0x2EC))[M2C_FIELD(arg1, u8 *, 0x322)];
    if (func_809F1EB8(arg1, arg0) != 0) {
        return 1;
    }
    if (func_809F15E8(arg0) != 0) {
        if (M2C_FIELD(sp24, s16 *, 0x1A0) == 0) {
            M2C_FIELD(arg1, s32 *, 0x18C) = (s32) M2C_FIELD(arg1, s32 *, 0x188);
            func_80151E7C(arg0, M2C_FIELD(((u8 **)(arg1 + 0x2EC))[M2C_FIELD(arg1, u8 *, 0x322)], u16 *, 0x198));
            func_8019FF78(0x4808);
            M2C_FIELD(arg1, s32 *, 0x358) = 0;
            M2C_FIELD(arg1, s32 *, 0x390) = 0;
            M2C_FIELD(arg1, s8 *, 0x321) = 0;
            func_809F15DC(arg1, &D_809F35B4);
            return 1;
        }
        func_8019FF78(0x4806);
        return 1;
    }
    return 0;
}
