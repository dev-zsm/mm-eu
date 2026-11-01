// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 unk0; u8 pad[7]; } Cmd;
extern u8 D_801CE928;
extern u8 D_801F84B0[];
extern void AudioThread_ProcessCmd(Cmd *);
void AudioThread_ProcessCmds(u32 a0) {
    Cmd *c;
    if (D_801F84B0[0x797A] == 0) {
        D_801CE928 = a0 >> 8;
    }
loop:
    if ((a0 & 0xFF) == D_801CE928) {
        D_801F84B0[0x797A] = 0;
        return;
    }
    c = (Cmd *)(D_801F84B0 + (D_801CE928 & 0xFF) * 8);
    D_801CE928 += 1;
    if (*(u8 *)((u8 *)c + 0x79F4) == 0xF8) {
        D_801F84B0[0x797A] = 1;
        return;
    }
    AudioThread_ProcessCmd((Cmd *)((u8 *)c + 0x79F4));
    *(u8 *)((u8 *)c + 0x79F4) = 0;
    goto loop;
}
