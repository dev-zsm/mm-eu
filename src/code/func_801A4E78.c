// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_801D3DD4;
extern f32 D_801D3DE0;
extern s8 D_801D3DE8;

extern void Audio_PlaySfx_IfNotInCutsceneImpl(u16 sfxId, f32 *pos, u8 token, f32 *freqScale, f32 *volume, s8 *reverbAdd);

void Audio_PlaySfx_IfNotInCutscene(u16 sfxId) {
    Audio_PlaySfx_IfNotInCutsceneImpl(sfxId, &D_801D3DD4, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
}
