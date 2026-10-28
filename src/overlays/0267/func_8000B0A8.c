// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFC68(u8 *, M2C_UNK, f32, u8 *); /* extern */
extern u8 *D_801EB7E0;
extern f32 D_809A2DD4;

void func_8000B0A8(u8 *arg0, M2C_UNK arg1) {
    f32 var_f0;

    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0xCA) {
        var_f0 = (f32) M2C_FIELD(D_801EB7E0, s16 *, 0x136A) + 15.0f;
    } else {
        var_f0 = (f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1370) + 8.0f;
    }
    func_800FFC68(arg0 + 0x17C, 0x3F800000, var_f0, arg0);
    if (M2C_FIELD(arg0, f32 *, 0x17C) < D_809A2DD4) {
        func_800B6490(arg0);
    }
}
