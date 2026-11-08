// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0478.h"

extern f32 D_80B18690;
extern f32 D_80B18694;
extern f32 D_80B18698;
extern f32 D_80B1869C;

void func_80000000(Actor *thisx) {
    f32 var_f0;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x14);
    M2C_FIELD(thisx, f32 *, 0xC4) = 0.0f;
    if (temp_v0 == 0) {
        var_f0 = D_80B18690;
        M2C_FIELD(thisx, f32 *, 0x58) = var_f0;
    } else {
        M2C_FIELD(thisx, f32 *, 0x58) = (f32) ((f32) temp_v0 * D_80B18694);
        var_f0 = D_80B18698;
    }
    temp_v0_2 = M2C_FIELD(thisx, s16 *, 0x18);
    if (temp_v0_2 == 0) {
        M2C_FIELD(thisx, f32 *, 0x60) = var_f0;
    } else {
        M2C_FIELD(thisx, f32 *, 0x60) = (f32) ((f32) temp_v0_2 * D_80B1869C);
    }
    M2C_FIELD(thisx, s16 *, 0xC0) = 0;
    temp_v0_3 = M2C_FIELD(thisx, s16 *, 0xC0);
    M2C_FIELD(thisx, f32 *, 0x5C) = var_f0;
    M2C_FIELD(thisx, s32 *, 0x13C) = 0;
    M2C_FIELD(thisx, s16 *, 0xBE) = temp_v0_3;
    M2C_FIELD(thisx, s16 *, 0xBC) = temp_v0_3;
}
