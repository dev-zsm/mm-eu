// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800BC370(u8 *, u8 *);                  /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_80975F40(u8 *);                      /* extern */
M2C_UNK func_80976178(u8 *);                      /* extern */
M2C_UNK func_809777B4(u8 *, u8 *);              /* extern */
extern f32 D_809790A4;

void func_80001FA4(u8 *arg0, u8 *arg1) {
    f32 temp_f0;

    if (func_80137070(arg0 + 0x144) != 0) {
        if ((func_800BC370(arg1, arg0) == 0) && (temp_f0 = M2C_FIELD(arg0, f32 *, 0x98), (temp_f0 < 170.0f)) && (temp_f0 > 140.0f) && (func_8008704C() < D_809790A4)) {
            func_80976178(arg0);
        } else if (M2C_FIELD(arg1, s32 *, 0x18840) & 1) {
            func_809777B4(arg0, arg1);
        } else {
            func_80975F40(arg0);
        }
    }
    if (M2C_FIELD(arg0, u16 *, 0x2A2) == 0) {
        func_800B8C4C(arg0, 0x383E);
    }
}
