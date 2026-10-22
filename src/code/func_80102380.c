// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Lights_New(s32, u8, u8, u8);             /* extern */

void LightContext_NewLights(void *arg0, s32 arg1) {
    Lights_New(arg1, M2C_FIELD(arg0, u8 *, 4), M2C_FIELD(arg0, u8 *, 5), M2C_FIELD(arg0, u8 *, 6));
}
