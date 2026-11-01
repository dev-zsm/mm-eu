#include "types.h"

extern u8 D_801FC848[];

extern s32 AudioLoad_GetRealTableIndex(s32 tableType, s32 id);

s32 AudioLoad_IsFontLoadComplete(s32 fontId) {
    if (fontId == 0xFF) {
        return 1;
    }
    if (D_801FC848[fontId] >= 2) {
        return 1;
    }
    if (D_801FC848[AudioLoad_GetRealTableIndex(1, fontId)] >= 2) {
        return 1;
    }
    return 0;
}
