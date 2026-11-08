#include "types.h"
#include "generated/code_funcs.h"

extern f32 D_801F4AA8[4];
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];

void Audio_PlaySfx_River(struct Vec3f *pos, f32 freqScale) {
    if (AudioSfx_IsPlaying(0x2006) == 0) {
        D_801F4AA8[0] = freqScale;
    } else if (freqScale != D_801F4AA8[0]) {
        D_801F4AA8[1] = freqScale;
        *(s32 *)&D_801F4AA8[3] = 0x28;
        D_801F4AA8[2] = (D_801F4AA8[1] - D_801F4AA8[0]) / 40.0f;
    }
    AudioSfx_PlaySfx(0x2006, pos, 4, D_801F4AA8, D_801D3DE0, D_801D3DE8);
}
