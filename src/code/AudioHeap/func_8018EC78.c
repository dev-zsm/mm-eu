#include "types.h"

typedef struct {
    u8 pad0[2];
    u8 unk2;
} SampleFont;

void AudioHeap_UnapplySampleCacheForFont(SampleFont *font, s32 arg1);

void AudioHeap_DiscardSampleCacheForFont(SampleFont *font, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 == font->unk2 || arg2 == font->unk2 || font->unk2 == 0) {
        AudioHeap_UnapplySampleCacheForFont(font, arg3);
    }
}
