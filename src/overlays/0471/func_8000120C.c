// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80B0AD58;
extern f32 D_80B0AD5C;

void func_8000120C(u8 *arg0) {
    s16 temp_v0;
    s16 var_v1;

    if (M2C_FIELD(arg0, s16 *, 0x288) >= 7) {
        M2C_FIELD(arg0, s32 *, 0x2BC) = (s32) (M2C_FIELD(arg0, s32 *, 0x2BC) - 0x10);
        M2C_FIELD(arg0, s32 *, 0x2C0) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C0) + 8);
        M2C_FIELD(arg0, f32 *, 0x2C4) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C4) + D_80B0AD58);
    } else {
        M2C_FIELD(arg0, s32 *, 0x2BC) = (s32) (M2C_FIELD(arg0, s32 *, 0x2BC) + 0x10);
        M2C_FIELD(arg0, s32 *, 0x2C0) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C0) - 8);
        M2C_FIELD(arg0, f32 *, 0x2C4) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C4) - D_80B0AD5C);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x288);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x288) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x288);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x288) = 0xC;
    }
}
