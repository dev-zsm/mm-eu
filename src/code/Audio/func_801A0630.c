// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 Audio_SetSyncedSfxFreqAndVolume(f32);
s32 AudioSfx_PlaySfx(u16, s32, s32, void *, void *, void *);
extern u8 D_801D3DE8[];
extern u8 D_801F4A9C[];
extern u8 D_801F4AA4[];

void Audio_PlaySfx_AtPosWithSyncedFreqAndVolume(s32 arg0, u16 arg1, f32 arg2) {
    Audio_SetSyncedSfxFreqAndVolume(arg2);
    AudioSfx_PlaySfx(arg1, arg0, 4, D_801F4AA4, D_801F4A9C, D_801D3DE8);
}
