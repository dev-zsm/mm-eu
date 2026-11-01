// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x2860];
    u8 *unk2860;
    u16 unk2864;
} SeqTbl;

extern SeqTbl D_801F84B0;
s32 AudioLoad_SyncLoadFont(s32 a0);

s32 AudioLoad_SyncLoadSeqFonts(s32 seqId, u32 *outFontId) {
    s32 ret;
    s32 pad[2];
    u32 fontId;
    s32 idx;
    s32 numFonts;

    if (seqId >= D_801F84B0.unk2864) {
        return 0;
    }
    fontId = 0xFF;
    idx = *(u16 *)((s32)D_801F84B0.unk2860 + seqId * 2);
    numFonts = D_801F84B0.unk2860[idx++];
    while (numFonts > 0) {
        fontId = D_801F84B0.unk2860[idx++];
        ret = AudioLoad_SyncLoadFont(fontId);
        numFonts--;
    }
    *outFontId = fontId;
    return ret;
}
