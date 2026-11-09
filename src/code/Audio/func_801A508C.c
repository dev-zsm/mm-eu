// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void Audio_MuteAllSeqExceptSystemAndOcarina(u16);
extern s8 D_801F4BEE;

void Audio_MuteSfxAndAmbienceSeqExceptSysAndOca(u16 arg0) {
    D_801F4BEE = 1;
    Audio_MuteAllSeqExceptSystemAndOcarina(arg0);
}
