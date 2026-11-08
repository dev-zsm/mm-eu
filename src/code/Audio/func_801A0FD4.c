// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801D14E0;
extern u8 D_801D3DE0;
extern u8 D_801D3DE8;

void Audio_PlaySfx_BigBells(struct Vec3f *pos, u8 volumeIndex) {
    AudioSfx_PlaySfx(0x2917, pos, 4, &D_801D3DE0, ((volumeIndex & 7) * 4) + &D_801D14E0, &D_801D3DE8);
}
