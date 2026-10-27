// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4C7A[3], D_801F4C7E[3], D_801F4C82[3];
extern u8 D_801F4CA0, D_801D0E68;
extern u8 D_801F4D58[24];
extern s32 D_801F4D70[24];
extern s32 D_801D0E64;

void AudioOcarina_ResetStaffs(void) {
    u8 i;

    D_801F4C7A[0] = 255;
    D_801F4C7A[1] = 255;
    D_801F4C7A[2] = 0;
    D_801F4C7E[0] = 255;
    D_801F4C7E[1] = 0;
    D_801F4C7E[2] = 0;
    D_801F4C82[0] = 255;
    D_801F4C82[1] = 255;
    D_801F4C82[2] = 0;
    D_801F4CA0 = 0;
    D_801D0E68 = 0;
    for (i = 0; i < 24; i++) {
        D_801F4D58[i] = 255;
        D_801F4D70[i] = 0;
    }
    D_801D0E64 = 0;
}
