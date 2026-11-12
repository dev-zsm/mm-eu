#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_8082E814(u8 *, M2C_UNK);             /* extern */
s32 func_8082F2D4(u8 *);                          /* extern */
M2C_UNK func_80832628(u8 *, f32 *, s16 *, f32, s32); /* extern */
s32 func_80832708(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80834A8C(s32, u8 *);                 /* extern */
s32 func_8083AA8C(s32, u8 *, s32);                /* extern */
M2C_UNK func_8083AE14(s32, u8 *, s16);            /* extern */
M2C_UNK func_80846CA8(u8 *);                      /* extern */
M2C_UNK func_80846EC8(s32, u8 *, s32, s32);       /* extern */
s32 func_808475C8(u8 *);                          /* extern */
M2C_UNK func_808476EC(u8 *, u8 *, f32, s16);    /* extern */
M2C_UNK func_80847788(s32, u8 *, f32 *, s16 *);   /* extern */
extern M2C_UNK D_8085C738;
extern s32 D_80862264;

void func_80023B3C(u8 *arg0, s32 arg1) {
    f32 sp2C;
    s16 sp2A;

    func_80846EC8(arg1, arg0, D_80862264, M2C_FIELD(arg0, s32 *, 0xAD0));
    func_80846CA8(arg0);
    func_8082E814(arg0, 0x10);
    if ((func_80832708(arg1, arg0, &D_8085C738, 1) == 0) && (func_8083AA8C(arg1, arg0, D_80862264) == 0)) {
        func_80832628(arg0, &sp2C, &sp2A, 0, arg1);
        if (sp2C == 0.0f) {
            func_80834A8C(arg1, arg0);
        } else if ((func_8082F2D4(arg0) == 0) && (func_808475C8(arg0) == 0)) {
            func_8083AE14(arg1, arg0, sp2A);
        } else {
            func_80847788(arg1, arg0, &sp2C, &sp2A);
        }
        func_808476EC(arg0, arg0 + 0xAD0, sp2C, sp2A);
    }
}
