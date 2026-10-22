// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern f32 D_801D7270;

void TransitionCircle_Start(void *arg0) {
    M2C_FIELD(arg0, f32 *, 8) = (f32) D_801D7270;
    if (M2C_FIELD(arg0, u8 *, 0x14) == 0) {
        M2C_FIELD(arg0, f32 *, 0x10) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0xC) = 1.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0xC) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x10) = 1.0f;
    }
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
}
