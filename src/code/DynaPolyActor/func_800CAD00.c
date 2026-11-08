// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 DynaPolyActor_IsPlayerOnTop(struct DynaPolyActor *dynaActor) {
    if (M2C_FIELD(dynaActor, u8 *, 0x158) & 2) {
        return 1;
    }
    return 0;
}
