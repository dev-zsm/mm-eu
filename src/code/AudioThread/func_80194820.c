// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801F84B0;

void AudioThread_ResetCmdQueue(void) {
    M2C_FIELD(&D_801F84B0, s8 *, 0x797A) = 0;
    M2C_FIELD(&D_801F84B0, u8 *, 0x7979) = (u8) M2C_FIELD(&D_801F84B0, u8 *, 0x7978);
}
