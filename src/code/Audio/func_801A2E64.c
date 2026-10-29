// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 AudioSeq_GetActiveSeqId(s32, void *);
extern s8 D_801CEFE0;
extern u8 D_801D3E04;
extern f32 D_801F4C60[3];
extern f32 D_801F4C6C;
extern s8 D_801F4C70;
extern u8 D_801F4C75;
extern s8 D_801F4C76;
void Audio_PlaySequenceAtPos(u8 arg0, f32 *arg1, u16 arg2, f32 arg3) {
    if (((((D_801CEFE0 == 0) && ((AudioSeq_GetActiveSeqId(0, arg1) & 0xFF) != 0x55)) && (D_801D3E04 != 0xC)) && (arg1 != ((void *) 0))) && ((D_801F4C75 != 0) || (AudioSeq_GetActiveSeqId(0, arg1) != 0x57))) {
        D_801F4C60[0] = arg1[0];
        D_801F4C60[1] = arg1[1];
        D_801F4C60[2] = arg1[2];
        D_801F4C6C = arg3;
        D_801F4C76 = 2;
        D_801F4C70 = arg2 & 0xFF;
        D_801F4C75 = arg0;
    }
}
