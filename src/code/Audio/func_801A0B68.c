// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEF88;
extern s8 D_801CEF8C;
extern s8 D_801CEF90;
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];
extern u8 D_801F4AC8[];
extern void AudioSfx_PlaySfx(u16, s32, s32, void *, void *, void *);
void Audio_PlaySfx_AtPosWithTimer(s32 a0, u16 a1, f32 a2) {
    D_801CEF88--;
    if (D_801CEF88 == 0) {
        AudioSfx_PlaySfx(a1, a0, 4, D_801F4AC8, D_801D3DE0, D_801D3DE8);
        if (a2 > 2.0f) {
            a2 = 2.0f;
        }
        D_801CEF88 = ((short) ((s32) (((f32) (D_801CEF90 - D_801CEF8C)) * (1.0f - a2)))) + D_801CEF90;
    }
}
