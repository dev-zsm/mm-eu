// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801F4CA0;
extern u8 D_801F4CA1;

void AudioOcarina_SetOcarinaDisableTimer(u16 arg0, u16 arg1) {
    D_801F4CA0 = arg1;
    D_801F4CA1 = arg0;
}
