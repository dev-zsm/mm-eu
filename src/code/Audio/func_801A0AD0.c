// FLAGS: -O2 -g0
#include "types.h"
extern u8 D_801CEF80[];
s32 AudioSfx_IsPlaying(s32);
void AudioSfx_SetChannelIO(s32, u16, s32);
void Audio_PlaySfx_AtPosWithFreqAndVolume(s32, u16, f32, void *);
void Audio_PlaySfx_WaterWheel(s32 a0, u16 id) {
    u8 flag = 0;
    if (id != 0x2173) {
        if (id == 0x2174) {
            if (AudioSfx_IsPlaying(0x2169) == 0) {
                flag = 1;
            }
        }
    } else {
        if (AudioSfx_IsPlaying(0x2168) == 0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        AudioSfx_SetChannelIO(a0, id, 0);
        Audio_PlaySfx_AtPosWithFreqAndVolume(a0, id, 1.0f, D_801CEF80);
    }
}
