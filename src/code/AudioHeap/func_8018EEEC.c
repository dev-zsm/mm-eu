// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioHeap_ApplySampleBankCacheInternal(M2C_UNK, s32);                /* extern */
extern s32 D_801F4960;

void AudioHeap_ApplySampleBankCache(s32 arg0) {
    D_801F4960 = 1;
    AudioHeap_ApplySampleBankCacheInternal(1, arg0);
}
