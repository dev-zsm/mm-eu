// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801D3E04;
extern s8 D_801F4C70;
extern s8 D_801F4C76;

void Audio_StopSequenceAtDefaultPos(void) {
    if (D_801D3E04 != 0xC) {
        D_801F4C76 = 1;
        D_801F4C70 = 0;
    }
}
