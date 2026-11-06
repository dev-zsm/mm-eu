// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Damaged(EnSlime* this, PlayState* play) {
    this->timer--;
    Math_StepToF(&this->actor.speed, 0.0f, 1.0f);
    if ((this->timer % 5) == 0) {
        this->wobbleRot.x = Rand_ZeroOne() * (M_PIf * 2);
        this->wobbleRot.z = Rand_ZeroOne() * (M_PIf * 2);
    }
    if (this->timer == 0) {
        if (this->actor.colChkInfo.health != 0) {
            this->collider.base.acFlags |= AC_ON;
            if ((this->actor.xzDistToPlayer < 280.0f) && (Player_GetMask(play) != PLAYER_MASK_STONE)) {
                EnSlime_SetupTurnToPlayer(this);
            } else {
                EnSlime_SetupIdle(this);
            }
        } else {
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EN_SLIME_BREAK);
            EnSlime_SetupDead(this);
        }
    }
}
