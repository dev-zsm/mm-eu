#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0088.h"

M2C_UNK func_8013C01C(u8 *, s32, M2C_UNK);        /* extern */
s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_808A7E28(s32, u8 *);                 /* extern */
extern u32 D_808AB8E4[];

void func_800012BC(u8 *arg0, s32 arg1) {
    s32 sp24;

    sp24 = D_808AB8E4[M2C_FIELD(arg0, s16 *, 0x1C)];
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        if ((M2C_FIELD(arg0, s16 *, 0x402) == 9) && (M2C_FIELD(arg0, s16 *, 0x1C) == 1)) {
            M2C_FIELD(arg0, s16 *, 0x402) = 1;
            func_8013C01C(arg0 + 0x144, sp24, 1);
        }
        func_808A7E28(arg1, arg0);
    }
}
