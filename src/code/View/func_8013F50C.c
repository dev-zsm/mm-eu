// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void View_GetOrtho(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    *arg1 = M2C_FIELD(arg0, f32 *, 0x18);
    *arg2 = M2C_FIELD(arg0, f32 *, 0x1C);
    *arg3 = M2C_FIELD(arg0, f32 *, 0x20);
}
