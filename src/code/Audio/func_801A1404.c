// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801CEF9C;
extern u8 D_801CDEE4[];
extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];

extern void AudioSfx_PlaySfx(u16 a0, s32 a1, s32 a2, void* a3, void* a4, void* a5);

void Audio_PlaySfx_IncreasinglyTransposed(s32 pos, u16 sfxId, s32 arg2) {
    AudioSfx_PlaySfx(sfxId, pos, 4, &D_801CDEE4[*(u8*)(D_801CEF9C + arg2) * 4 + 0x9C], D_801D3DE0, D_801D3DE8);
    if (D_801CEF9C < 0xF) {
        D_801CEF9C++;
    }
}
