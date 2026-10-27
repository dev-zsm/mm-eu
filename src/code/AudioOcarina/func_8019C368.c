// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801F4D70[];
extern u8 D_801D0E60;
extern s32 D_801D0E64;
void AudioOcarina_Start(s32 mask);

void AudioOcarina_StartWithSongNoteLengths(u32 mask) {
    u8 i;

    for (i = 0; i < 24; i++) {
        if ((1 << i) & mask) {
            D_801F4D70[i] = 0;
        } else {
            D_801F4D70[i] = 0xFF;
        }
    }
    D_801D0E60 = 1;
    D_801D0E64 = mask;
    AudioOcarina_Start(mask);
}
