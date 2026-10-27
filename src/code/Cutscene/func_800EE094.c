// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801EAE3C;

s32 Cutscene_IsPlaying(void *arg0) {
    s32 var_v1;

    var_v1 = D_801EAE3C != 0;
    if (var_v1 == 0) {
        var_v1 = M2C_FIELD(arg0, u8 *, 0x1F2C) != 0;
    }
    return var_v1 & 0xFF;
}
