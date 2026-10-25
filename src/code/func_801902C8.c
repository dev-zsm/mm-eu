// FLAGS: -O2 -g0
#include "types.h"

extern u8 D_801F84B0[];

extern void AudioHeap_ApplySampleBankCache(void);

void AudioLoad_SetSampleFontLoadStatusAndApplyCaches(s32 sampleBankId, s32 status) {
    u8 *entry;

    if (sampleBankId != 0xFF) {
        entry = D_801F84B0 + sampleBankId;
        if (entry[0x4368] != 5) {
            entry[0x4368] = status;
        }
        if (entry[0x4368] == 5 || entry[0x4368] == 2) {
            AudioHeap_ApplySampleBankCache();
        }
    }
}
