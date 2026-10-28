// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB44(s16);                             /* extern */
s32 func_80137070(u8 *);                          /* extern */
s32 func_8087C000(u8 *, s32);                     /* extern */
M2C_UNK func_8087D7A0(u8 *);                      /* extern */
M2C_UNK func_8087D9C8(u8 *);                      /* extern */
M2C_UNK func_8087DC84(u8 *);                      /* extern */
M2C_UNK func_8087ECB0(u8 *);                      /* extern */
M2C_UNK func_808851A0(s32, f32 *, s16 *);           /* extern */
extern f32 D_808889B0;

void func_80002834(u8 *arg0, s32 arg1) {
    f32 sp24;
    s16 sp22;

    sp22 = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_808851A0(arg0 + 0x264, &sp24, &sp22);
    if (sp24 > 10.0f) {
        if (func_8087C000(arg0, arg1) == 1) {
            if (func_800FEB44(sp22) <= -0.5f) {
                func_8087ECB0(arg0);
            } else if (func_800FEB44(sp22) <= D_808889B0) {
                func_8087D9C8(arg0);
            } else {
                func_8087DC84(arg0);
            }
        } else if (M2C_FIELD(arg0, s16 *, 0x32) != M2C_FIELD(arg0, s16 *, 0x3EC)) {
            func_8087D9C8(arg0);
        }
    }
    if (func_80137070(arg0 + 0x1A4) != 0) {
        func_8087D7A0(arg0);
    }
}
