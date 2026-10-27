// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEFE0;
extern u8 D_801D3E04;
extern f32 D_801D3DD4[3];
extern f32 D_801F4C60[3];
extern f32 D_801D86B0;
extern f32 D_801F4C6C;
extern u8 D_801F4C70;
extern u8 D_801F4C75;
extern u8 D_801F4C76;

void Audio_PlaySequenceAtDefaultPos(u8 arg0, u16 arg1) {
    if ((D_801CEFE0 == 0) && (D_801D3E04 != 0xC)) {
        D_801F4C60[0] = D_801D3DD4[0];
        D_801F4C60[1] = D_801D3DD4[1];
        D_801F4C60[2] = D_801D3DD4[2];
        D_801F4C6C = D_801D86B0;
        D_801F4C76 = 0x80;
        D_801F4C70 = arg1;
        D_801F4C75 = arg0;
    }
}
