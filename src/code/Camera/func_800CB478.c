// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Camera_SetFocalActorAtOffset(void *arg0, void *arg1) {
    M2C_FIELD(arg0, f32 *, 0xE4) = (f32) (M2C_FIELD(arg0, f32 *, 0x50) - M2C_FIELD(arg1, f32 *, 0));
    M2C_FIELD(arg0, f32 *, 0xE8) = (f32) (M2C_FIELD(arg0, f32 *, 0x54) - M2C_FIELD(arg1, f32 *, 4));
    M2C_FIELD(arg0, f32 *, 0xEC) = (f32) (M2C_FIELD(arg0, f32 *, 0x58) - M2C_FIELD(arg1, f32 *, 8));
}
