// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];

extern u8* AudioSfx_AddSfxSetting(s32 a0);
extern void AudioSfx_PlaySfx(u16 a0, s32 a1, s32 a2, void* a3, void* a4, void* a5);

void Audio_PlaySfx_WithSfxSettingsReverb(s32 pos, u16 sfxId) {
    u8* reverb;

    if ((sfxId == 0x3941) || (sfxId == 0x3942)) {
        AudioSfx_PlaySfx(sfxId, pos, 4, D_801D3DE0, D_801D3DE0, D_801D3DE8);
        return;
    }
    reverb = AudioSfx_AddSfxSetting(pos);
    if (reverb != NULL) {
        AudioSfx_PlaySfx(sfxId, pos, 4, D_801D3DE0, D_801D3DE0, reverb + 8);
    }
}
