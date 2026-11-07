// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AAD450(DmChar05* this, PlayState* play) {
    if (play->csCtx.curFrame == 262) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_EVIL_POWER);
    }

    if (play->csCtx.curFrame > 318) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_MASK_FLOAT - SFX_FLAG);
    }
}
