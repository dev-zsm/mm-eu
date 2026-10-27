// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEFE0;
extern void AudioSfx_PlaySfx(u16 sfxId, void *pos, u8 token, f32 *freqScale, f32 *volume, s8 *reverbAdd);

void Audio_PlaySfx_IfNotInCutsceneImpl(u16 sfxId, void *pos, u8 token, f32 *freqScale, f32 *volume, s8 *reverbAdd) {
    if (D_801CEFE0 == 0) {
        AudioSfx_PlaySfx(sfxId, pos, token, freqScale, volume, reverbAdd);
    }
}
