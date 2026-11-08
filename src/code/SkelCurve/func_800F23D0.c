// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void SkelCurve_Clear(struct SkelCurve *skelCurve) {
    M2C_FIELD(skelCurve, s8 *, 0) = 0;
    M2C_FIELD(skelCurve, s32 *, 4) = 0;
    M2C_FIELD(skelCurve, s32 *, 8) = 0;
    M2C_FIELD(skelCurve, f32 *, 0x18) = 0.0f;
    M2C_FIELD(skelCurve, f32 *, 0x14) = 0.0f;
    M2C_FIELD(skelCurve, f32 *, 0x10) = 0.0f;
    M2C_FIELD(skelCurve, f32 *, 0xC) = 0.0f;
    M2C_FIELD(skelCurve, s32 *, 0x1C) = 0;
}
