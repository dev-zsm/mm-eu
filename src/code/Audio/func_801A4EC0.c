// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4BEE;

// 2 instr differ: the ROM spills a0 before the sb instead of in its delay slot.
void Audio_MuteSfxAndAmbienceSeqExceptSystemAndOcarina(u8 arg0) {
    D_801F4BEE = arg0;
}
