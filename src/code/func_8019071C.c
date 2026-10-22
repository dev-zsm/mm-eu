// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioLoad_AsyncLoad(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32); /* extern */

void AudioLoad_AsyncLoadSampleBank(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    AudioLoad_AsyncLoad(2, arg0, 0, arg2, arg3);
}
