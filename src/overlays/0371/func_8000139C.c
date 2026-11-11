#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
M2C_UNK func_80151E7C(s32, s32);                    /* extern */
u8 func_801529DC(s32);                              /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_80A70638(s32, u8 *);                 /* extern */
s32 func_80A70778(u8 *);                          /* extern */
M2C_UNK func_80A7160C(s32, u8 *);                 /* extern */
s32 func_80A716AC(s32, u8 *, s32);                /* extern */
s32 func_80A7304C(u8 *);                          /* extern */

void func_8000139C(u8 *arg0, s32 arg1) {
    u8 sp2F;
    u16 pad2[2];
    u8 sp27;
    s16 temp_v0;

    sp2F = func_801529DC(arg1 + 0x4908);
    sp27 = M2C_FIELD(arg0, u8 *, 0x34C);
    if (func_80A7304C(arg0) == 0) {
        M2C_FIELD(arg0, s16 *, 0x330) = 3;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x330);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x330) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x400) = 0xFF;
    M2C_FIELD(arg0, s32 *, 0x384) = 1;
    func_80A70638(arg1, arg0);
    if (sp2F == 5) {
        func_80115540(arg1, 6);
        if (func_80A716AC(arg1, arg0, arg1 + 0x14) == 0) {
            func_80A7160C(arg1, arg0);
            if (sp27 != M2C_FIELD(arg0, u8 *, 0x34C)) {
                func_80151E7C(arg1, func_80A70778(arg0) & 0xFFFF);
                func_8019FF78(0x4809);
            }
        }
    }
}
