// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEF88;
extern s8 D_801CEF8C;
extern s8 D_801CEF90;

void Audio_SetSfxTimerLerpInterval(s8 arg0, s8 arg1) {
    D_801CEF88 = 1;
    D_801CEF8C = arg1;
    D_801CEF90 = arg0;
}
