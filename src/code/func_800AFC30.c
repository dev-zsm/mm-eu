// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801DB840;

s32 Effect_GetPlayState(void) {
    return D_801DB840;
}
