// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4BEE;

void Audio_MuteSfxAndAmbienceSeqExceptSystemAndOcarina(u8 arg0) {
    D_801F4BEE = arg0;
}
