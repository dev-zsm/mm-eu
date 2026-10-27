// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801F7574[];
void AudioSeq_ResetSequenceRequests(u8 a) { D_801F7574[a] = 0; }
