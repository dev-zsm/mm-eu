// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_step.h"

void ObjTokeiStep_InitTimers(ObjTokeiStep* this) {
    s32 i;

    this->panels[0].startFallingTimer = 0;
    for (i = 1; i < ARRAY_COUNT(this->panels); i++) {
        this->panels[i].startFallingTimer = 10;
    }
}
