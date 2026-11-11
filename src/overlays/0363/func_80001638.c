#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0363.h"

M2C_UNK func_800A8248(s32, M2C_UNK, u8 *, s16);   /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
M2C_UNK func_800BDFB0(u8 *);                      /* extern */
M2C_UNK func_80A59E34(u8 *);                      /* extern */
extern u16 D_80A5A8BC[];

void func_80001638(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x28D) & 2) {
        func_800BDFB0(arg0);
        if (((s32) M2C_FIELD(arg0, u8 *, 0xB7) <= 0) && (M2C_FIELD(arg0, s16 *, 0x1D4) != 3)) {
            func_800BB80C(arg1, arg0);
            M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
            func_800B8C4C(arg0, 0x39F5);
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x218);
            if (temp_v0 >= 0) {
                func_800A8248(arg1, 0, arg0 + 0x24, D_80A5A8BC[temp_v0]);
            }
            M2C_FIELD(arg0, u8 *, 0xB7) = 0U;
            func_80A59E34(arg0);
        }
    }
    if (M2C_FIELD(arg0, u8 *, 0x28C) & 4) {
        M2C_FIELD(arg0, f32 *, 0x70) = -10.0f;
    }
}
