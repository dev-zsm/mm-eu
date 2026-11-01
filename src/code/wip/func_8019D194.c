#include "types.h"

extern u8 D_801F4CA0;
extern u8 D_801F4CA1;

void AudioOcarina_SetOcarinaDisableTimer(s32 arg0, s32 arg1) {
    D_801F4CA0 = arg1;
    D_801F4CA1 = arg0;
}
