// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800BAE44(s32, u8 *, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_8012F9A8(s32, M2C_UNK);                    /* extern */
extern M2C_UNK D_80BFEC60;
extern M2C_UNK D_80BFF840;

void func_80000108(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_800FF8DC(arg0, &D_80BFF840);
    func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x29A, 0.0f, 0.0f, 0.0f, 0, 0, 0, 4);
    temp_v0 = func_8012F9A8(arg1 + 0x17D88, 0x146);
    M2C_FIELD(arg0, s32 *, 0x160) = temp_v0;
    if (temp_v0 < 0) {
        func_800B6490(arg0);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80BFEC60;
}
