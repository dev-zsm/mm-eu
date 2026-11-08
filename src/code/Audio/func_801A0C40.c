// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s8 D_801CEF88;
extern s8 D_801CEF8C;
extern s8 D_801CEF90;

void Audio_SetSfxTimerLerpInterval(s8 timerLerpRange1, s8 timerLerpRange2) {
    D_801CEF88 = 1;
    D_801CEF8C = timerLerpRange2;
    D_801CEF90 = timerLerpRange1;
}
