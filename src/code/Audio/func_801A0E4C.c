#include "types.h"

extern f32 D_801F4AA8[4];
extern s32 AudioSfx_IsPlaying(s32);
extern void AudioSfx_PlaySfx(s32, s32, s32, f32 *, void *, void *);
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];

void Audio_PlaySfx_River(s32 arg0, f32 arg1) {
    if (AudioSfx_IsPlaying(0x2006) == 0) {
        D_801F4AA8[0] = arg1;
    } else if (arg1 != D_801F4AA8[0]) {
        D_801F4AA8[1] = arg1;
        *(s32 *)&D_801F4AA8[3] = 0x28;
        D_801F4AA8[2] = (D_801F4AA8[1] - D_801F4AA8[0]) / 40.0f;
    }
    AudioSfx_PlaySfx(0x2006, arg0, 4, D_801F4AA8, D_801D3DE0, D_801D3DE8);
}
