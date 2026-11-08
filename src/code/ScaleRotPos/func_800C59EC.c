// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 ScaleRotPos_IsEqual(struct ScaleRotPos *a, struct ScaleRotPos *b) {
    if ((M2C_FIELD(b, f32 *, 0) != M2C_FIELD(a, f32 *, 0)) || (M2C_FIELD(b, f32 *, 4) != M2C_FIELD(a, f32 *, 4)) || (M2C_FIELD(b, f32 *, 8) != M2C_FIELD(a, f32 *, 8)) || (M2C_FIELD(b, s16 *, 0xC) != M2C_FIELD(a, s16 *, 0xC)) || (M2C_FIELD(b, s16 *, 0xE) != M2C_FIELD(a, s16 *, 0xE)) || (M2C_FIELD(b, s16 *, 0x10) != M2C_FIELD(a, s16 *, 0x10)) || (M2C_FIELD(b, f32 *, 0x14) != M2C_FIELD(a, f32 *, 0x14)) || (M2C_FIELD(b, f32 *, 0x18) != M2C_FIELD(a, f32 *, 0x18)) || (M2C_FIELD(b, f32 *, 0x1C) != M2C_FIELD(a, f32 *, 0x1C))) {
        return 0;
    }
    return 1;
}
