#include "types.h"

extern u8 D_801F84B0[];

void AudioLoad_SetSampleFontLoadStatus(s32 fontId, s32 status) {
    u8 *p;

    if (fontId != 0xFF) {
        p = D_801F84B0 + fontId;
        if (p[0x4368] != 5) {
            p[0x4368] = status;
        }
    }
}
