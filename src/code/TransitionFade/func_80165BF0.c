// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 TransitionFade_IsDone(void *thisx) {
    return M2C_FIELD(thisx, u8 *, 1);
}
