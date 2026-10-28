// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C604C(s32, s32, s32);               /* extern */
s32 func_800C98D0(s32, s32, u8);                    /* extern */
s32 func_80A05E80(u8 *);                          /* extern */
s32 func_80A06278(u8 *, s32);                     /* extern */
M2C_UNK func_80A069E4(u8 *, s32);                 /* extern */
M2C_UNK func_80A06A08(u8 *);                      /* extern */
M2C_UNK func_80A07038(u8 *);                      /* extern */
M2C_UNK func_80A07458(u8 *);                      /* extern */

void func_800014FC(u8 *arg0, s32 arg1) {
    s32 sp20;
    s32 temp_v0;

    if (func_80A05E80(arg0) != -1) {
        func_80A069E4(arg0, arg1);
    }
    func_80A06A08(arg0);
    temp_v0 = func_80A06278(arg0, arg1);
    if ((temp_v0 != 0) || ((M2C_FIELD(arg0, f32 *, 0x160) - M2C_FIELD(arg0, f32 *, 0x28)) > 300.0f)) {
        sp20 = temp_v0;
        if (func_800C98D0(arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, u8 *, 0x85)) == 0xC) {
            func_800C604C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
            M2C_FIELD(arg0, s32 *, 0x13C) = 0;
            func_80A07458(arg0);
            return;
        }
    }
    if (temp_v0 != 0) {
        func_80A07038(arg0);
    }
}
