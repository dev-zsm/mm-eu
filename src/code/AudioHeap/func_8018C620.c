// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void AudioHeap_InitPool(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = (arg1 + 0xF) & ~0xF;
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 4) = temp_v0;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (arg2 - (arg1 & 0xF));
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}
