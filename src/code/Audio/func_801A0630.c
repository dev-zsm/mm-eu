// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801D3DE8[];
extern u8 D_801F4A9C[];
extern u8 D_801F4AA4[];

void Audio_PlaySfx_AtPosWithSyncedFreqAndVolume(struct Vec3f *pos, u16 sfxId, f32 freqVolParam) {
    Audio_SetSyncedSfxFreqAndVolume(freqVolParam);
    AudioSfx_PlaySfx(sfxId, pos, 4, D_801F4AA4, D_801F4A9C, D_801D3DE8);
}
