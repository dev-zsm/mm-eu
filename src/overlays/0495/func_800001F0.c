// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B45A64;
extern f32 D_80B461F0;
extern f32 D_80B461F4;
extern f32 D_80B461F8;
extern f32 D_80B461FC;

void func_800001F0(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x3A0) == 1) {
        M2C_FIELD(arg0, f32 *, 0x390) = 2.0f;
        M2C_FIELD(arg0, f32 *, 0x394) = (f32) D_80B461F0;
        M2C_FIELD(arg0, f32 *, 0x398) = (f32) D_80B461F4;
    } else {
        M2C_FIELD(arg0, f32 *, 0x390) = 4.0f;
        M2C_FIELD(arg0, f32 *, 0x394) = (f32) D_80B461F8;
        M2C_FIELD(arg0, f32 *, 0x398) = (f32) D_80B461FC;
    }
    M2C_FIELD(arg0, s16 *, 0x39C) = 0;
    M2C_FIELD(arg0, s16 *, 0x39E) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x38C) = &D_80B45A64;
}
