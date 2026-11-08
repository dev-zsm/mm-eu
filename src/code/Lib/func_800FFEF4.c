// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Lib_PlaySfx_AtPos(s32 a0, u16 a1) {
    Audio_PlaySfx_AtPos(a0, a1);
}
