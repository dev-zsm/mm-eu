// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void DynaPolyActor_SetPlayerAbove(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x158) = (u8) (M2C_FIELD(arg0, u8 *, 0x158) | 4);
}
