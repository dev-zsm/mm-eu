#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x10];
} FontEntry;

typedef struct {
    /* 0x0000 */ u8 pad0[0x2854];
    /* 0x2854 */ s16 *unk2854;
    /* 0x2858 */ u8 pad2858[0x10];
    /* 0x2868 */ u8 *unk2868;
} AudioCtx;

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 fontId;
} Sample;

extern AudioCtx D_801F84B0;
extern s32 AudioHeap_SearchCaches();
extern s32 AudioLoad_IsFontLoadComplete();
extern void AudioHeap_UnapplySampleCacheForFont();

void AudioHeap_DiscardSampleCacheEntry(Sample *s) {
    s16 n = *D_801F84B0.unk2854;
    s32 i = 0;
    s32 off = 0;
    FontEntry *e;

    if (n > 0) {
        do {
            e = (FontEntry *)(D_801F84B0.unk2868 + off);
            if (((e->unk2 != 0xFF && e->unk2 == s->fontId) || (e->unk3 != 0xFF && e->unk3 == s->fontId) || s->fontId == 0 || s->fontId == 0xFE) &&
                AudioHeap_SearchCaches(1, 2, i) != 0 && AudioLoad_IsFontLoadComplete(i) != 0) {
                AudioHeap_UnapplySampleCacheForFont(s, i);
            }
            i++;
            off += 0x14;
        } while (i != n);
    }
}
