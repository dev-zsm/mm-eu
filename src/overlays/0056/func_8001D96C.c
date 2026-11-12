#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, s32);                        /* extern */
M2C_UNK func_808325D4(u8 *);                      /* extern */
M2C_UNK func_80832628(u8 *, f32 *, s16 *, f32, s32); /* extern */
s32 func_80832708(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80836038(u8 *, s32);                 /* extern */
M2C_UNK func_80839E6C(u8 *, s32);                 /* extern */
s32 func_8083DAF8(u8 *, f32, s16);                /* extern */
extern M2C_UNK D_8085C734;

void func_8001D96C(u8 *arg0, s32 arg1) {
    s32 sp34;
    f32 sp30;
    s16 sp2E;

    sp34 = func_80136480(arg1, arg0 + 0x240);
    func_808325D4(arg0);
    if ((func_80832708(arg1, arg0, &D_8085C734, 1) == 0) && (func_80832628(arg0, &sp30, &sp2E, 0, arg1), (M2C_FIELD(arg0, f32 *, 0xAD0) == 0.0f))) {
        M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        if (func_8083DAF8(arg0, sp30, sp2E) > 0) {
            func_80839E6C(arg0, arg1);
            return;
        }
        if ((sp30 != 0.0f) || (sp34 != 0)) {
            func_80836038(arg0, arg1);
        }
    }
}
