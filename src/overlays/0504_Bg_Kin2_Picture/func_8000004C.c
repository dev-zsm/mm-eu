// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_picture.h"

void BgKin2Picture_SpawnSkulltula(BgKin2Picture* this, PlayState* play2) {
    PlayState* play = play2;
    s32 skulltulaSpawnParams;

    if (!BG_KIN2_PICTURE_SKULLTULA_COLLECTED(&this->dyna.actor)) { 
        skulltulaSpawnParams = BG_KIN2_PICTURE_SKULLTULA_SPAWN_PARAM(&this->dyna.actor);
        if (!BgKin2Picture_IsSkulltulaCollected(play, skulltulaSpawnParams) &&
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_SW, this->dyna.actor.home.pos.x,
                        this->dyna.actor.home.pos.y + 23.0f, this->dyna.actor.home.pos.z, 0,
                        this->dyna.actor.home.rot.y, 0, skulltulaSpawnParams)) {
            Audio_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
        }
    }
}
