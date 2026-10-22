// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

u8 TransitionFade_IsDone(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 1);
}
