// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
s8 func_80B70234(s32, u8 *);                      /* extern */
M2C_UNK func_80B703D4(u8 *, s32);                 /* extern */
s32 func_80B7062C(u8 *);                          /* extern */
M2C_UNK func_80B70CE8(u8 *);                      /* extern */
M2C_UNK func_80B70E5C(u8 *, s32);                 /* extern */

void func_800012CC(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    s8 temp_v0_2;

    func_80137070(arg0 + 0x194);
    M2C_FIELD(arg0, f32 *, 0x70) = 1.5f;
    temp_v0 = func_80B7062C(arg0);
    if (temp_v0 != 1) {
        if (temp_v0 == 2) {
            func_80B703D4(arg0, arg1);
        }
    } else {
        func_80B70CE8(arg0);
        M2C_FIELD(arg0, s8 *, 0x301) = 0;
    }
    temp_v0_2 = func_80B70234(arg1, arg0);
    M2C_FIELD(arg0, s8 *, 0x301) = temp_v0_2;
    if (temp_v0_2 & 0xFF) {
        func_80B70CE8(arg0);
        M2C_FIELD(arg0, s16 *, 0x2FA) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    }
    func_80B70E5C(arg0, arg1);
}
