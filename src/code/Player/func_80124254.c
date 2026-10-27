// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Player_ReleaseLockOn(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x730) = 0;
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) & ~0x2000);
}
