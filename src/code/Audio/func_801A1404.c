// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"

extern u8 D_801CEF9C;
extern u8 D_801CDEE4[];
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];


void Audio_PlaySfx_IncreasinglyTransposed(s32 pos, u16 sfxId, s32 arg2) {
    AudioSfx_PlaySfx(sfxId, pos, 4, &D_801CDEE4[*(u8*)(D_801CEF9C + arg2) * 4 + 0x9C], D_801D3DE0, D_801D3DE8);
    if (D_801CEF9C < 0xF) {
        D_801CEF9C++;
    }
}
