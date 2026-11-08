// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioLoad_AsyncLoad(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32); /* extern */

void AudioLoad_AsyncLoadSeq(s32 seqId, s32 arg1, s32 retData, struct OSMesgQueue *retQueue) {
    AudioLoad_AsyncLoad(0, seqId, 0, retData, retQueue);
}
