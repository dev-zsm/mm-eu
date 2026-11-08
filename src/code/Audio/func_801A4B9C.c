// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s8 D_801CEFE8;

void Audio_SetEnvReverb(s8 reverb) {
    D_801CEFE8 = reverb & 0x7F;
}
