// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 ScaleRotPos_IsEqual(void *arg0, void *arg1) {
    if ((M2C_FIELD(arg1, f32 *, 0) != M2C_FIELD(arg0, f32 *, 0)) || (M2C_FIELD(arg1, f32 *, 4) != M2C_FIELD(arg0, f32 *, 4)) || (M2C_FIELD(arg1, f32 *, 8) != M2C_FIELD(arg0, f32 *, 8)) || (M2C_FIELD(arg1, s16 *, 0xC) != M2C_FIELD(arg0, s16 *, 0xC)) || (M2C_FIELD(arg1, s16 *, 0xE) != M2C_FIELD(arg0, s16 *, 0xE)) || (M2C_FIELD(arg1, s16 *, 0x10) != M2C_FIELD(arg0, s16 *, 0x10)) || (M2C_FIELD(arg1, f32 *, 0x14) != M2C_FIELD(arg0, f32 *, 0x14)) || (M2C_FIELD(arg1, f32 *, 0x18) != M2C_FIELD(arg0, f32 *, 0x18)) || (M2C_FIELD(arg1, f32 *, 0x1C) != M2C_FIELD(arg0, f32 *, 0x1C))) {
        return 0;
    }
    return 1;
}
