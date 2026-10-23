// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u16 D_801EAE36;
void Environment_ForcePlaySequence(u16 a0) { D_801EAE36 = a0; }
