// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s8 D_801CEFE0;

void Audio_SetCutsceneFlag(s8 flag) {
    D_801CEFE0 = flag;
}
