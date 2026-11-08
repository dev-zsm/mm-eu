// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_dharma.h"

void BgIkanaDharma_Update(Actor* thisx, PlayState* play) {
    BgIkanaDharma* this = (BgIkanaDharma*)thisx;

    this->actionFunc(this, play);
    if (this->actionFunc == BgIkanaDharma_WaitForHit) {
        DynaPolyActor* actorBelow;
        s32 pad[2];

        ref_func_800B4AEC(play, &this->dyna.actor, 30.0f);
        actorBelow = DynaPoly_GetActor(&play->colCtx, this->dyna.actor.floorBgId);
        if (actorBelow == NULL) {
            Actor_MoveWithGravity(&this->dyna.actor);
            Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
            if (this->dyna.actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
                s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

                Quake_SetSpeed(quakeIndex, 21536);
                Quake_SetPerturbations(quakeIndex, 4, 0, 0, 0);
                Quake_SetDuration(quakeIndex, 12);

                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
            }
        } else {
            if (actorBelow->actor.id == ACTOR_BG_IKANA_DHARMA) {
                this->dyna.actor.world.pos.y = actorBelow->actor.world.pos.y + 60.0f;
            } else {
                this->dyna.actor.world.pos.y = this->dyna.actor.floorHeight;
            }

            this->dyna.actor.velocity.y = 0.0f;
        }
    } else {
        f32 wallCheckRadius = this->dyna.actor.scale.x * 300.0f;
        wallCheckRadius = CLAMP_MIN(wallCheckRadius, 2.0f);

        Actor_MoveWithGravity(&this->dyna.actor);
        Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 20.0f, wallCheckRadius, 0.0f,
                                UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);
    }

    Actor_SetFocus(&this->dyna.actor, 40.0f);
}
