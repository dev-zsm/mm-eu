// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_elevator.h"

void BgDblueElevator_Move(BgDblueElevator* this, PlayState* play) {
    s32 index = BG_DBLUE_ELEVATOR_GET_INDEX(&this->dyna.actor);
    BgDblueElevatorStruct1* ptr = &ref_D_80B92960[index];
    s32 waterFlow = ptr->getWaterFlow(this, play);

    f32 targetPosOffset;
    s32 hasReachedEnd;
    s32 isDeactivated;
    f32 posStep;

    Vec3f basePosOffset;
    Vec3f posOffset;
    f32 nearWaterSurfaceCheck;

    s32 pad;

    if ((waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_STOPPED) ||
        (waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_BOTH_DIRECTIONS)) {
        isDeactivated = Math_StepToF(&this->posStep, 0.0f, ptr->decelerationStep);
    } else {
        isDeactivated = false;
        Math_StepToF(&this->posStep, ptr->targetPosStep, ptr->accelerationStep);
    }

    if (this->direction > 0) {
        targetPosOffset = ptr->targetPosOffset;
    } else {
        targetPosOffset = -ptr->targetPosOffset;
    }

    if (this->posStep <= 1.1f) {
        posStep = 1.1f;
    } else {
        posStep = this->posStep;
    }

    if (Math_SmoothStepToF(&this->posOffset, targetPosOffset, 0.4f, posStep, 1.0f) < 0.001f) {
        hasReachedEnd = true;
    } else {
        hasReachedEnd = false;
    }

    if (!ptr->isHorizontal) {
        this->dyna.actor.world.pos.y = this->posOffset + this->dyna.actor.home.pos.y;
        if (CHECK_FLAG_ALL(this->dyna.actor.flags, ACTOR_FLAG_INSIDE_CULLING_VOLUME) && (this->isWithinWaterBoxXZ)) {
            if (this->direction > 0) {
                nearWaterSurfaceCheck = ((this->dyna.actor.world.pos.y + -10.0f) - this->waterSurfacePosY) *
                                        ((this->dyna.actor.prevPos.y + -10.0f) - this->waterSurfacePosY);
            } else {
                nearWaterSurfaceCheck = ((this->dyna.actor.world.pos.y + -30.0f) - this->waterSurfacePosY) *
                                        ((this->dyna.actor.prevPos.y + -30.0f) - this->waterSurfacePosY);
            }
            if (nearWaterSurfaceCheck <= 0.0f) {
                BgDblueElevator_SpawnRipplesAndSplashes(this, play);
            }
        }
    } else {
        Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
        basePosOffset.x = this->posOffset;
        basePosOffset.y = 0.0f;
        basePosOffset.z = 0.0f;
        Matrix_MultVec3f(&basePosOffset, &posOffset);
        Math_Vec3f_Sum(&this->dyna.actor.home.pos, &posOffset, &this->dyna.actor.world.pos);
    }

    if (isDeactivated) {
        BgDblueElevator_SetupWaitActivation(this);
    } else {
        if (hasReachedEnd) {
            this->direction = -this->direction;
            BgDblueElevator_SetupPause(this);
        }
    }
}
