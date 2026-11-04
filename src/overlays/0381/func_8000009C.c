// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char02.h"

void DmChar02_PlaySfxForDroppingOcarinaCutscene(DmChar02* this, PlayState* play) {
    switch (play->csCtx.curFrame) {
        case 95:
            Actor_PlaySfx(&this->actor, NA_SE_EV_OCARINA_BOUND_0);
            break;

        case 101:
        case 105:
        case 112:
            Actor_PlaySfx(&this->actor, NA_SE_EV_OCARINA_BOUND_1);
            break;
    }
}
