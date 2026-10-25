// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801D3DD4[];
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];
extern void AudioSfx_PlaySfx(u16 a0, u8 *a1, s32 a2, u8 *a3, u8 *a4, u8 *a5);

void Audio_PlaySfx_2(u16 sfxId) {
    AudioSfx_PlaySfx(sfxId, D_801D3DD4, 4, D_801D3DE0, D_801D3DE0, D_801D3DE8);
}
