#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80BDF3D4(u8 *, s32);                 /* extern */
M2C_UNK func_80BDF41C(u8 *);                      /* extern */
M2C_UNK func_80BDF4B0(u8 *);                      /* extern */
extern M2C_UNK D_80BDF8EC;

void func_80000AF0(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_80BDF3D4(arg0, arg1);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x41C);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x41C) = (s16) (temp_v0 - 1);
    } else {
        func_80BDF41C(arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80BDF8EC;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
        func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
    }
    func_80BDF4B0(arg0);
}
