// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Land(EnSlime* this, PlayState* play) {
    f32 scaleY;
    f32 rotXZ;
    f32 scaleXZ;

    EnSlime_Blink(this);
    this->timer--;
    scaleY = ((this->timer / 5) + 1) * 1.6f;
    rotXZ = sqrtf(this->timer) * 0.2f;
    scaleXZ = ((Math_CosF(this->timer * (2 * M_PIf / 5)) * (0.05f * scaleY)) + 1.0f) * 0.01f;
    this->actor.scale.x = scaleXZ;
    this->actor.scale.z = scaleXZ;
    if (this->timer < 15) {
        this->actor.scale.y = (1.0f - (Math_SinF(this->timer * (2 * M_PIf / 5)) * (0.04f * scaleY))) * 0.01f;
    }
    this->actor.shape.rot.x = Rand_CenteredFloat(0x200) * rotXZ;
    this->actor.shape.rot.z = Rand_CenteredFloat(0x200) * rotXZ;

    if (Actor_WorldDistXZToPoint(&this->actor, &this->actor.home.pos) > this->distLimit) {
        EnSlime_SetupMoveToHome(this);
    } else if ((Player_GetMask(play) != PLAYER_MASK_STONE) && (this->actor.xzDistToPlayer < 280.0f) &&
               (this->timer < 12)) {
        EnSlime_SetupTurnToPlayer(this);
    } else if (this->timer == 0) {
        EnSlime_SetupIdle(this);
    }
}
