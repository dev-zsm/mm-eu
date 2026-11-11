#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0344.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800EDCC4(u8 *, s32, s32);            /* extern */
s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_80A372DC(u8 *, s32);                 /* extern */
extern u32 D_80A3835C[];

void func_80000B08(u8 *arg0, s32 arg1) {
    s32 sp24;
    u32 temp_v1;
    s32 sp20;
    u32 temp_v0;
    s32 temp_v0_2;

    if (func_800EE03C(arg1, 0x69) != 0) {
        temp_v0 = func_800EDFA0(arg1, 0x69);
        sp24 = temp_v0;
        temp_v1 = *M2C_FIELD((arg1 + (temp_v0 * 4)), u16 **, 0x1F4C);
        if ((temp_v1 & 0xFF) != M2C_FIELD(arg0, u8 *, 0x1DC)) {
            sp20 = (s32) temp_v1;
            func_80A372DC(arg0, D_80A3835C[temp_v1]);
            M2C_FIELD(arg0, u8 *, 0x1DC) = (u8) temp_v1;
        }
        if ((M2C_FIELD(arg0, s32 *, 0x398) == 4) && (func_80137C58(arg0 + 0x148, 0x40000000) != 0)) {
            func_800B8C4C(arg0, 0x39F6);
        }
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x398);
        if (((temp_v0_2 == 3) || (temp_v0_2 == 6)) && (func_80137C58(arg0 + 0x148, M2C_FIELD(arg0, s32 *, 0x158)) != 0)) {
            func_80A372DC(arg0, M2C_FIELD(arg0, s32 *, 0x398) + 1);
        }
        func_800EDCC4(arg0, arg1, sp24);
    }
}
