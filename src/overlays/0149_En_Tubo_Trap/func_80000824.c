// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tubo_trap.h"

void EnTuboTrap_Idle(EnTuboTrap* this, PlayState* play) {
    static s8 sTransformationHeight[] = {
        40, 40, 40, 25, 28,
    };
    Player* player = GET_PLAYER(play);
    f32 currentHeight;
    f32 transformationHeight;
    s16 startingRotation;

    if ((this->actor.xzDistToPlayer < 200.0f) && (this->actor.world.pos.y <= player->actor.world.pos.y)) {
        startingRotation = this->actor.home.rot.z;
        if ((startingRotation == 0) || (this->actor.playerHeightRel <= (startingRotation * 10.0f))) {
            Actor_ChangeCategory(play, &play->actorCtx, &this->actor, ACTORCAT_ENEMY);
            currentHeight = this->actor.world.pos.y;
            this->actor.flags |=
                (ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_UPDATE_CULLING_DISABLED); 

            transformationHeight = sTransformationHeight[player->transformation];

            this->targetHeight = player->actor.world.pos.y + transformationHeight;
            if (this->targetHeight < currentHeight) {
                this->targetHeight = currentHeight;
                this->targetHeight += transformationHeight;
            }
            this->originPos = this->actor.world.pos;
            Actor_PlaySfx(&this->actor, NA_SE_EV_POT_MOVE_START);
            this->actionFunc = EnTuboTrap_Levitate;
        }
    }
}
