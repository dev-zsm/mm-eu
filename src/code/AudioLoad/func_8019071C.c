// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioLoad_AsyncLoad(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32); /* extern */

void AudioLoad_AsyncLoadSampleBank(s32 sampleBankId, s32 arg1, s32 retData, struct OSMesgQueue *retQueue) {
    AudioLoad_AsyncLoad(2, sampleBankId, 0, retData, retQueue);
}
