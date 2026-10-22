// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEFE0;

void Audio_SetCutsceneFlag(s8 arg0) {
    D_801CEFE0 = arg0;
}
