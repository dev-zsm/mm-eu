#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_80A372DC(u8 *, s32);                 /* extern */
extern s32 D_80A3833C[];

s32 func_80000548(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x38A) == 0) {
        M2C_FIELD(arg0, s16 *, 0x38C) = 0;
        M2C_FIELD(arg0, s16 *, 0x38A) = 1;
        M2C_FIELD(arg0, s16 *, 0x388) = (s16) ((u32) M2C_FIELD(arg1, u32 *, 0x9C) % 5U);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x38C);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x38C) = (s16) (temp_v0 - 1);
    }
    if (func_80137C58(arg0 + 0x148, M2C_FIELD(arg0, s32 *, 0x158)) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x38C) == 0) {
            M2C_FIELD(arg0, s16 *, 0x38C) = func_800FF250(0x14, 0x14);
            M2C_FIELD(arg0, s16 *, 0x388) = (s16) (M2C_FIELD(arg0, s16 *, 0x388) + 3);
            M2C_FIELD(arg0, s16 *, 0x388) = (s16) ((s16) M2C_FIELD(arg0, s16 *, 0x388) % 5);
        }
        func_80A372DC(arg0, D_80A3833C[M2C_FIELD(arg0, s16 *, 0x388)]);
        M2C_FIELD(arg0, f32 *, 0x160) = 0.0f;
    }
    M2C_FIELD(arg0, s16 *, 0x386) = 0;
    return 0;
}
