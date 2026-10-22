// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801F84B0;

void AudioThread_GetSampleBankIdsOfFont(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_v0;

    temp_v0 = arg0 * 0x14;
    *arg1 = (s32) M2C_FIELD((M2C_FIELD(&D_801F84B0, s32 *, 0x2868) + temp_v0), u8 *, 2);
    *arg2 = (s32) M2C_FIELD((M2C_FIELD(&D_801F84B0, s32 *, 0x2868) + temp_v0), u8 *, 3);
}
