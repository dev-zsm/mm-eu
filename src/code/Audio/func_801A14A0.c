// FLAGS: -O2 -g0
#include "types.h"
#include "code_funcs.h"

extern u8 D_801CDEE4[];
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];


void Audio_PlaySfx_Transposed(void *pos, u16 sfxId, s8 semitone) {
    AudioSfx_PlaySfx(sfxId, pos, 4, D_801CDEE4 + 0x9C + semitone * 4, D_801D3DE0, D_801D3DE8);
}
