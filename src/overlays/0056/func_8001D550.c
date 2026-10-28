// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8082F2D4(u8 *);                          /* extern */
M2C_UNK func_80832628(u8 *, f32 *, s16 *, M2C_UNK, s32); /* extern */
s32 func_80832708(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80839514(u8 *, s32);                 /* extern */
s32 func_80839B7C(u8 *, f32 *, s16 *, f32);       /* extern */
M2C_UNK func_80839E6C(u8 *, s32);                 /* extern */
M2C_UNK func_8083BFC0(u8 *, s32);                 /* extern */
M2C_UNK func_8083C230(u8 *, f32, s16);            /* extern */
M2C_UNK func_8083EC70(u8 *, s32);                 /* extern */
extern u8 *D_801EB7E0;
extern M2C_UNK D_8085C718;

void func_8001D550(u8 *arg0, s32 arg1) {
    f32 sp2C;
    s16 sp2A;

    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x20);
    func_8083EC70(arg0, arg1);
    if (func_80832708(arg1, arg0, &D_8085C718, 1) == 0) {
        if (func_8082F2D4(arg0) != 0) {
            func_80839E6C(arg0, arg1);
            return;
        }
        func_80832628(arg0, &sp2C, &sp2A, 0x3C9374BC, arg1);
        if (M2C_FIELD(arg0, u8 *, 0x153) == 4) {
            sp2C *= 1.5f;
        }
        if (func_80839B7C(arg0, &sp2C, &sp2A, (f32) M2C_FIELD(D_801EB7E0, s16 *, 0x6A) / 100.0f) == 0) {
            func_8083C230(arg0, sp2C, sp2A);
            func_8083BFC0(arg0, arg1);
            if ((M2C_FIELD(arg0, f32 *, 0xAD0) == 0.0f) && (sp2C == 0.0f)) {
                func_80839514(arg0, arg1);
            }
        }
    }
}
