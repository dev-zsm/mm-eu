// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_y2lift.h"

void ObjY2lift_Update(Actor* thisx, PlayState* play) {
    ObjY2lift* this = (ObjY2lift*)thisx;
    f32 temp_fv0 = this->dyna.actor.world.pos.y;
    f32 targetVelocityY = 0.0f;
    s32 isPlayerOnTop = DynaPolyActor_IsPlayerOnTop(&this->dyna);

    if (isPlayerOnTop || DynaPolyActor_IsActorOnTop(&this->dyna)) {
        if (!this->unk15D) {
            this->unk15D = true;
            this->unk15F = 12;
        } else if ((this->unk15F == 0) && isPlayerOnTop) {
            this->unk15C = 16;
        }
    } else {
        this->unk15D = false;
    }
    if (DECR(this->unk15C) != 0) {
        temp_fv0 = this->dyna.actor.home.pos.y + 180.0f;
        targetVelocityY = 2.0f;
    } else if (!isPlayerOnTop && (this->dyna.actor.velocity.y <= 0.0f)) {
        temp_fv0 = this->dyna.actor.home.pos.y;
        targetVelocityY = -2.0f;
    }
    Math_StepToF(&this->dyna.actor.velocity.y, targetVelocityY, 0.1f);
    this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;
    if (((this->dyna.actor.world.pos.y - temp_fv0) * targetVelocityY) >= 0.0f) {
        this->dyna.actor.world.pos.y = temp_fv0;
        this->dyna.actor.velocity.y = 0.0f;
        if (!this->unk15E) {
            this->unk15E = true;
            this->unk15F = 12;
        }
    } else {
        this->unk15E = false;
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_PLATE_LIFT_LEVEL - SFX_FLAG);
    }
    if (DECR(this->unk15F) != 0) {
        this->dyna.actor.shape.yOffset = (2.0f * (this->unk15F & 1)) * this->unk15F;
    }
}
