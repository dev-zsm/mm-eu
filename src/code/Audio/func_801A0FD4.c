// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioSfx_PlaySfx(s32, s32, s32, void *, void *, void *);
extern u8 D_801D14E0;
extern u8 D_801D3DE0;
extern u8 D_801D3DE8;

void Audio_PlaySfx_BigBells(s32 arg0, u8 arg1) {
    AudioSfx_PlaySfx(0x2917, arg0, 4, &D_801D3DE0, ((arg1 & 7) * 4) + &D_801D14E0, &D_801D3DE8);
}
