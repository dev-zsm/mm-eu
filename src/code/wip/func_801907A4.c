#include "types.h"

typedef struct {
    u8 pad0[0x2860];
    u8 *sequenceFontTable;
} AudioTable;

extern AudioTable D_801F84B0;

u8 *AudioLoad_GetFontsForSequence(s32 seqId, s32 *outNumFonts) {
    u16 offset = ((u16 *)D_801F84B0.sequenceFontTable)[seqId];
    s32 count = D_801F84B0.sequenceFontTable[offset];

    *outNumFonts = count;
    if (count != 0) {
        return &D_801F84B0.sequenceFontTable[offset + 1];
    }
    return NULL;
}
