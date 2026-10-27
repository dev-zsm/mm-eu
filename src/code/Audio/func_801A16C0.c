// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_801D3DE0;
extern s32 D_801D3DE8;

void AudioSfx_SetChannelIO(s32 arg0, u16 sfxId, u8 ioPort);
void AudioSfx_PlaySfx(u16 sfxId, s32 pos, s32 token, f32 *arg3, f32 *arg4, s32 *arg5);

void Audio_PlaySfx_AtPosWithChannelIO(s32 pos, u16 sfxId, u8 ioPort) {
    AudioSfx_SetChannelIO(pos, sfxId, ioPort);
    AudioSfx_PlaySfx(sfxId, pos, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
}
