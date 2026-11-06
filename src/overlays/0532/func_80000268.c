// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_boat.h"

void ObjBoat_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjBoat* this = (ObjBoat*)thisx;
    Player* player = GET_PLAYER(play);
    s32 isPlayerOnTop = DynaPolyActor_IsPlayerOnTop(&this->dyna);
    f32 speedTarget = 0.0f;
    s16 yawTarget = this->dyna.actor.shape.rot.y;
    Vec3f nextPoint;

    if (isPlayerOnTop || DynaPolyActor_IsActorOnTop(&this->dyna)) {
        if ((this->timer == 0) &&
            (OBJBOAT_GET_4000(thisx) || (isPlayerOnTop && (this->curPointIndex == this->lastPointIndex)))) {
            this->direction = -this->direction;
            if (this->direction > 0) {
                this->lastPointIndex = this->maxPointIndex;
            } else {
                this->lastPointIndex = 0;
            }
            this->timer = 60;
        }
    } else if (this->dyna.actor.speed == 0.0f) {
        if (this->timer != 0) {
            this->timer--;
        }
    }

    if (this->curPointIndex != this->lastPointIndex) {
        yawTarget = ObjBoat_GetNextPoint(this, &nextPoint);
        if (Math_Vec3f_DistXZ(&this->dyna.actor.world.pos, &nextPoint) < 200.0f) {
            this->curPointIndex += this->direction;
            if (this->curPointIndex == this->lastPointIndex) {
                if (OBJBOAT_GET_4000(thisx)) {
                    this->curPointIndex = 0;
                } else if (this->dyna.actor.speed == 0.0f) {
                    this->curPointIndex = 0;
                    this->direction = -1;
                }
            }
        } else {
            speedTarget = this->direction * (OBJBOAT_GET_4000(thisx) ? 5.0f : 3.0f);
        }
    }

    if (player->csAction != PLAYER_CSACTION_26) {
        Math_ScaledStepToS(&this->dyna.actor.shape.rot.y, yawTarget, (s32)(fabsf(this->dyna.actor.speed) * 40.0f));
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;
        Math_StepToF(&this->dyna.actor.speed, speedTarget, 0.05f);
        Actor_MoveWithGravity(&this->dyna.actor);
        if (this->dyna.actor.speed != 0.0f) {
            Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_PIRATE_SHIP - SFX_FLAG);
        }
    }
    ObjBoat_SetRotations(this);
}
