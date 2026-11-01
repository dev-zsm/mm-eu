// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"

extern u8 D_801D3DE0;
extern u8 D_801D3DE8;


void Audio_PlaySfx_Randomized(void *pos, u16 baseSfxId, u8 randLim) {
    u8 r = AudioThread_NextRandom() % randLim;

    AudioSfx_PlaySfx(baseSfxId + r, pos, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
}
