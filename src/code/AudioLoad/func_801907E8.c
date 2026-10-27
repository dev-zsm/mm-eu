// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x2860];
    u8 *unk2860;
} AudioCtx;

extern AudioCtx D_801F84B0;
extern s32 AudioLoad_GetRealTableIndex(s32 a, u8 b);
extern s32 AudioHeap_SearchPermanentCache(s32 a, s32 b);
extern void AudioLoad_DiscardFont(s32 a);
extern void AudioLoad_SetFontLoadStatus(s32 a, s32 b);

void AudioLoad_DiscardSeqFonts(s32 arg0) {
    s32 n;
    s32 off;
    s32 id;

    off = ((u16 *)D_801F84B0.unk2860)[arg0];
    n = *(off + D_801F84B0.unk2860);
    off++;
    if (n > 0) {
        do {
            n--;
            id = AudioLoad_GetRealTableIndex(1, *(off++ + D_801F84B0.unk2860));
            if (AudioHeap_SearchPermanentCache(1, id) == 0) {
                AudioLoad_DiscardFont(id);
                AudioLoad_SetFontLoadStatus(id, 0);
            }
        } while (n > 0);
    }
}
