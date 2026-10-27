// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801D3DE0[];
void Audio_PlaySfx_AtPosWithFreqAndVolume(void *pos, u16 sfxId, f32 freq, u8 *arg3);

void Audio_PlaySfx_AtPosWithFreq(void *pos, u16 sfxId, f32 freq) {
    Audio_PlaySfx_AtPosWithFreqAndVolume(pos, sfxId, freq, D_801D3DE0);
}
