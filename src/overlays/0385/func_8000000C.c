// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char06.h"

void DmChar06_Init(Actor* thisx, PlayState* play) {
    DmChar06* this = (DmChar06*)thisx;

    SET_WEEKEVENTREG(WEEKEVENTREG_CLEARED_SNOWHEAD_TEMPLE);
    Actor_SetScale(&this->actor, 1.0f);
    this->alpha = 255;
    DmChar06_SetupAction(this, DmChar06_HandleCutscene);
}
