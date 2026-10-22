// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern u16 D_801E6F06;
extern void *D_801EB7E0;

s32 Environment_GetTimeSpeed(s32 arg0) {
    s16 temp_v0;
    s32 var_v1;

    var_v1 = 0;
    temp_v0 = M2C_FIELD(D_801EB7E0, s16 *, 0x32);
    if (temp_v0 != 0) {
        var_v1 = (D_801E6F06 + temp_v0) & 0xFFFF;
    }
    return var_v1;
}
