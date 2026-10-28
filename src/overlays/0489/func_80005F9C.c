// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FEE3C(s32, M2C_UNK, M2C_UNK, u8 *); /* extern */
extern f32 D_80B33C94;

void func_80005F9C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    func_800FEE3C(arg0 + 0x70, 0x43160000, 0x40800000, arg0);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (M2C_FIELD(arg0, f32 *, 0x68) * D_80B33C94);
    func_800B680C(arg0);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2F0);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2F0) = (s16) (temp_v0 - 1);
        return;
    }
    func_800B6490(arg0);
}
