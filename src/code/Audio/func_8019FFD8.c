// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801D3DD4[];
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];

void Audio_PlaySfx_2(u16 sfxId) {
    AudioSfx_PlaySfx(sfxId, D_801D3DD4, 4, D_801D3DE0, D_801D3DE0, D_801D3DE8);
}
