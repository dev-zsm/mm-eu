// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern f32 D_801CEF84;
extern f32 D_801D3DE0;
extern s8 D_801D3DE8;

extern void AudioSfx_PlaySfx(u16 sfxId, Vec3f *pos, u8 token, f32 *freqScale, f32 *volume, s8 *reverbAdd);

void Audio_PlaySfx_AtPosWithVolume(Vec3f *pos, u16 sfxId, f32 volume) {
    D_801CEF84 = volume;
    AudioSfx_PlaySfx(sfxId, pos, 4, &D_801D3DE0, &D_801CEF84, &D_801D3DE8);
}
