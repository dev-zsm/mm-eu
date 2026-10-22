// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 Math_CosS(s16);                             /* extern */
f32 Math_SinS(s16);                             /* extern */

void Actor_SetSpeeds(void *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (Math_CosS(M2C_FIELD(arg0, s16 *, 0x30)) * arg1);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (-Math_SinS(M2C_FIELD(arg0, s16 *, 0x30)) * arg1);
}
