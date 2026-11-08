// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

f32 Math_CosS(s16);                             /* extern */
f32 Math_SinS(s16);                             /* extern */

void Actor_SetSpeeds(struct Actor *actor, f32 speed) {
    M2C_FIELD(actor, f32 *, 0x70) = (f32) (Math_CosS(M2C_FIELD(actor, s16 *, 0x30)) * speed);
    M2C_FIELD(actor, f32 *, 0x68) = (f32) (-Math_SinS(M2C_FIELD(actor, s16 *, 0x30)) * speed);
}
