// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A99DE0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A9BB38(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A9B828;
extern M2C_UNK D_80A9BE38;

void func_800024F4(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s32 temp_a1;

    func_80A9BB38(arg0, arg1);
    func_80137070(arg0 + 0x148);
    if (M2C_FIELD(arg0, f32 *, 0x98) < 200.0f) {
        func_80A99DE0(arg0, 1);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9BE38;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    temp_a1 = temp_v0 & 0x7F;
    if ((((s32) (temp_v0 & 0x780) >> 7) == 1) && (temp_a1 != 0x7F) && (func_800B5B20(arg1, temp_a1) != 0)) {
        func_80A99DE0(arg0, 2);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9B828;
    }
}
