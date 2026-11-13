#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B5B64(s32, s32);                    /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A99DE0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A9BB38(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A9B828;
extern M2C_UNK D_80A9B914;
extern M2C_UNK D_80A9BBE0;

void func_80002288(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_a1_2;

    func_80137070(arg0 + 0x148);
    func_80A9BB38(arg0, arg1);
    if (func_800B8254(arg0, arg1) != 0) {
        if (((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x780) >> 7) == 3) {
            func_80A99DE0(arg0, 2);
        } else {
            func_80A99DE0(arg0, 5);
        }
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F;
        M2C_FIELD(arg0, s32 *, 0x3E0) = 6;
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9B914;
        if (temp_a1 != 0x7F) {
            func_800B5B64(arg1, temp_a1);
        }
    } else {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
        temp_a1_2 = temp_v0 & 0x7F;
        if ((((s32) (temp_v0 & 0x780) >> 7) == 1) && (temp_a1_2 != 0x7F) && (func_800B5B20(arg1, temp_a1_2) != 0)) {
            func_80A99DE0(arg0, 2);
            M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9B828;
            return;
        }
        if (M2C_FIELD(arg0, f32 *, 0x98) > 150.0f) {
            func_80A99DE0(arg0, 1);
            M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) | 0x10);
            M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9BBE0;
            return;
        }
        if (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) {
            func_800B8398(arg0, arg1, 0x42F00000);
        }
    }
}
