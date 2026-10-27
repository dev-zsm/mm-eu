// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u16 D_801D1774;

u16 AudioVoice_GetWord(void) {
    return D_801D1774;
}
