// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_SetupStunned(EnBat* this) {
    if (this->actionFunc != EnBat_Stunned) {
        this->actor.shape.yOffset = 700.0f;
        this->actor.velocity.y = 0.0f;
        this->actor.speed = 0.0f;
        this->actor.world.pos.y += 13.0f;
    }

    Actor_PlaySfx(&this->actor, NA_SE_EN_COMMON_FREEZE);
    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_BLUE, 255, COLORFILTER_BUFFLAG_OPA, this->timer);
    this->actionFunc = EnBat_Stunned;
}
