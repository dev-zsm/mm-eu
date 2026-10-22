// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEFE8;

void Audio_SetEnvReverb(s8 arg0) {
    D_801CEFE8 = arg0 & 0x7F;
}
