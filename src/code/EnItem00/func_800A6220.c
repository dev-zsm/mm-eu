// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Actor_SetScale(void *, M2C_UNK);             /* extern */
M2C_UNK Actor_SetObjectDependency(s32, void *);                 /* extern */
extern f32 D_801D4720;

void EnItem00_SetObject(void *arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    Actor_SetObjectDependency(arg1, arg0);
    Actor_SetScale(arg0, 0x3F000000);
    M2C_FIELD(arg0, f32 *, 0x154) = 0.5f;
    *arg2 = 0.0f;
    *arg3 = D_801D4720;
    M2C_FIELD(arg0, s16 *, 0x30) = 0x4000;
}
