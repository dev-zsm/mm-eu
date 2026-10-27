// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Environment_IsSceneUpsideDown(void *arg0) {
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xA4);
    var_v1 = 0;
    if ((temp_v0 == 0x59) || (temp_v0 == 0x18)) {
        var_v1 = 1;
    }
    return var_v1;
}
