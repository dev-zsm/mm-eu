// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, s32, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80BA4C00(u8 *);                      /* extern */
M2C_UNK func_80BA4CC4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BA529C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BA55A0(u8 *);                      /* extern */
M2C_UNK func_80BA57B8(u8 *, M2C_UNK);             /* extern */

void func_80001310(u8 *arg0, M2C_UNK arg1) {
    func_80BA529C(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80BA57B8(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x1DC) != 0) {
        func_80BA4C00(arg0);
        func_80BA55A0(arg0);
        if (func_800B7164(arg0, 0x38E0) != 0) {
            func_8013CD14(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x274), 0x41F00000, 0, M2C_FIELD(arg0, u16 *, 0x262) & 7);
        }
        func_80BA4CC4(arg0, arg1);
    }
}
