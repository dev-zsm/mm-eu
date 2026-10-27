// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 func_80086BA0(f32, f32);                        /* extern */
extern f32 D_801D4E8C;
extern f32 D_801D4E90;

s16 Camera_CalcXZAngle(void *arg0, void *arg1) {
    return (s16) (s32) ((func_80086BA0(M2C_FIELD(arg1, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0), M2C_FIELD(arg1, f32 *, 8) - M2C_FIELD(arg0, f32 *, 8)) * D_801D4E8C * D_801D4E90) + 0.5f);
}
