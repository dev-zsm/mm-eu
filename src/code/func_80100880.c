// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s16 D_801E6F26;

s32 LifeMeter_SaveInterfaceHealth(void *arg0) {
    D_801E6F26 = M2C_FIELD(arg0, s16 *, 0x16C36);
    return 1;
}
