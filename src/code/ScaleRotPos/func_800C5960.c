// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void ScaleRotPos_Init(struct ScaleRotPos *srp) {
    M2C_FIELD(srp, f32 *, 8) = 1.0f;
    M2C_FIELD(srp, f32 *, 4) = 1.0f;
    M2C_FIELD(srp, f32 *, 0) = 1.0f;
    M2C_FIELD(srp, s16 *, 0xC) = 0;
    M2C_FIELD(srp, s16 *, 0xE) = 0;
    M2C_FIELD(srp, s16 *, 0x10) = 0;
    M2C_FIELD(srp, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(srp, f32 *, 0x18) = 0.0f;
    M2C_FIELD(srp, f32 *, 0x14) = 0.0f;
}
