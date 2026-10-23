#include "types.h"
extern u8 D_801F84B0;
void AudioLoad_SetFontLoadStatus(s32 a0, s32 a1) {
    u8 *p;
    if (a0 != 0xFF) {
        p = a0 + (u8 *)&D_801F84B0;
        if (p[0x4398] != 5) {
            p[0x4398] = a1;
        }
    }
}
