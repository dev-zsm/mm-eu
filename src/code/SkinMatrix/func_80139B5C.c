// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void SkinMatrix_SetTranslate(union MtxF *mf, f32 x, f32 y, f32 z) {
    M2C_FIELD(mf, f32 *, 4) = 0.0f;
    M2C_FIELD(mf, f32 *, 8) = 0.0f;
    M2C_FIELD(mf, f32 *, 0xC) = 0.0f;
    M2C_FIELD(mf, f32 *, 0x10) = 0.0f;
    M2C_FIELD(mf, f32 *, 0x18) = 0.0f;
    M2C_FIELD(mf, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(mf, f32 *, 0x20) = 0.0f;
    M2C_FIELD(mf, f32 *, 0x24) = 0.0f;
    M2C_FIELD(mf, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(mf, f32 *, 0) = 1.0f;
    M2C_FIELD(mf, f32 *, 0x14) = 1.0f;
    M2C_FIELD(mf, f32 *, 0x28) = 1.0f;
    M2C_FIELD(mf, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(mf, f32 *, 0x30) = x;
    M2C_FIELD(mf, f32 *, 0x34) = y;
    M2C_FIELD(mf, f32 *, 0x38) = z;
}
