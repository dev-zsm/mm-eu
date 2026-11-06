// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_boat.h"

void ObjBoat_UpdateCutscene(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjBoat* this = (ObjBoat*)thisx;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_511)) {
        CsCmdActorCue* cue = play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_511)];

        if (this->cueId != cue->id) {
            this->dyna.actor.shape.rot.x = cue->rot.x;
            if (cue->id != 1) {
                Path* path = &play->setupPathList[OBJBOAT_GET_PATH_INDEX(&this->dyna.actor)];

                if (cue->id == 3) {
                    path = &play->setupPathList[path->additionalPathIndex];
                }

                this->maxPointIndex = path->count;
                this->pathPoints = Lib_SegmentedToVirtual(path->points);
                Math_Vec3s_ToVec3f(&this->dyna.actor.world.pos, this->pathPoints);
                this->dyna.actor.speed = cue->rot.z * (45.0f / 0x2000);
                this->pathPoints++;
                this->curPointIndex = 1;
            }

            this->cueId = cue->id;
        } else {
            if (cue->id != 1) {
                Vec3f posTarget;
                f32 distRemaining;

                Math_Vec3s_ToVec3f(&posTarget, this->pathPoints);
                distRemaining = Math_Vec3f_StepTo(&this->dyna.actor.world.pos, &posTarget, this->dyna.actor.speed);
                if ((this->curPointIndex < this->maxPointIndex) && (distRemaining < this->dyna.actor.speed)) {
                    this->pathPoints++;
                    this->curPointIndex++;
                }
            }

            if (cue->id != 3) {
                ObjBoat_SetRotations(this);
                if (cue->id == 2) {
                    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_PIRATE_SHIP - SFX_FLAG);
                }
            } else {
                
                this->dyna.actor.shape.rot.y += 0x7D0;
                this->dyna.actor.shape.rot.x += 0x3E8;
                this->dyna.actor.shape.rot.z += 0x1F4;
            }
        }
    }
}
