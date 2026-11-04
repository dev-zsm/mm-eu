// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_torch2.h"

void EnTorch2_Update(Actor* thisx, PlayState* play) {
    EnTorch2* this = (EnTorch2*)thisx;
    u16 targetAlpha;
    u16 remainingFrames;
    s32 pad[2];

    if (this->state == TORCH2_STATE_IDLE) {
        this->actor.update = EnTorch2_UpdateIdle;
        return;
    }

    this->actor.gravity = -1.0f;
    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 30.0f, 20.0f, 70.0f, UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);

    if (this->framesUntilNextState == 0) {
        remainingFrames = 0;
    } else {
        remainingFrames = --this->framesUntilNextState;
    }

    if (remainingFrames == 0) {
        if (this->state == TORCH2_STATE_INITIALIZED) {
            
            if (this->alpha == 0) {
                Math_Vec3f_Copy(&this->actor.world.pos, &this->actor.home.pos);
                this->actor.shape.rot.y = this->actor.home.rot.y;
                this->state = TORCH2_STATE_FADING_IN;
            }
            targetAlpha = 0;
        } else if (this->state == TORCH2_STATE_FADING_IN) {
            
            if ((this->actor.xzDistToPlayer > 32.0f) || (fabsf(this->actor.playerHeightRel) > 70.0f)) {
                this->state = TORCH2_STATE_SOLID;
            }
            targetAlpha = 60;
        } else {
            
            Collider_UpdateCylinder(&this->actor, &this->collider);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
            targetAlpha = 255;
        }
        Math_StepToS(&this->alpha, targetAlpha, 8);
    }
}
