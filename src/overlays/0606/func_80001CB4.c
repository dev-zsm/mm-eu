// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80BD5FF8(u8 *);                      /* extern */
M2C_UNK func_80BD60F4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD6184(u8 *);                      /* extern */
M2C_UNK func_80BD638C(u8 *);                      /* extern */
M2C_UNK func_80BD6740(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD68E0(u8 *, M2C_UNK);             /* extern */

void func_80001CB4(u8 *arg0, M2C_UNK arg1) {
    func_80BD6740(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80BD68E0(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x298) != 0) {
        func_80BD5FF8(arg0);
        func_80BD6184(arg0);
        func_80BD638C(arg0);
        func_8013CD14(arg0, arg1, 0x42700000, 0x41F00000, 0, M2C_FIELD(arg0, u16 *, 0x3D0) & 7);
        func_800B680C(arg0);
        func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
        func_80BD60F4(arg0, arg1);
    }
}
