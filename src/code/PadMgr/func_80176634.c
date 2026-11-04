// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_RumbleSet(u8 enable[MAXCONTROLLERS]) {
    s32 i;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        sPadMgrInstance->rumbleEnable[i] = enable[i];
    }
    sPadMgrInstance->rumbleOnTimer = 24;
}
