// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801D3DE0;
extern u8 D_801D3DE8;

extern u32 AudioThread_NextRandom(void);
extern void AudioSfx_PlaySfx(u16 sfxId, void *pos, u8 token, void *arg3, void *arg4, void *arg5);

void Audio_PlaySfx_Randomized(void *pos, u16 baseSfxId, u8 randLim) {
    u8 r = AudioThread_NextRandom() % randLim;

    AudioSfx_PlaySfx(baseSfxId + r, pos, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
}
