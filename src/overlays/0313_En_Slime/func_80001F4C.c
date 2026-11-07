// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Revive(EnSlime* this, PlayState* play) {
    f32 rescaleFactor1;
    f32 rescaleFactor2;

    this->timer++;
    if (this->timer == 28) {
        this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        this->collider.base.acFlags |= AC_ON;
        this->actor.shape.rot.y = this->actor.home.rot.y;
        EnSlime_SetupMoveInDirection(this);
    } else {
        if (this->timer < 12) {
            rescaleFactor1 = this->timer * (0.01f / 12.0f); 
            this->reviveScale.x = rescaleFactor1;
            this->reviveScale.z = rescaleFactor1;
            this->reviveScale.y = 2.0f * rescaleFactor1;
            this->reviveRotY = this->timer * (0x4000 / 10.0f);
        } else if (this->timer < 20) {
            rescaleFactor1 = (this->timer - 12) * (0.01f / 16.0f);
            rescaleFactor2 = 0.01f + rescaleFactor1;
            this->reviveScale.x = rescaleFactor2;
            this->reviveScale.z = rescaleFactor2;
            this->reviveScale.y = 2.0f * (0.01f - rescaleFactor1);
            this->reviveRotY = this->timer * (0x4000 / 10.0f);
        } else if (this->timer < 24) {
            rescaleFactor1 = (this->timer - 20) * (0.01f / 3.0f); 
            rescaleFactor2 = 0.015f - rescaleFactor1;
            this->reviveScale.x = rescaleFactor2;
            this->reviveScale.z = rescaleFactor2;
            this->reviveScale.y = (2.0f * rescaleFactor1) + 0.01f;
            Actor_SetScale(&this->actor, 1.5f * rescaleFactor1);
            this->reviveRotY = ((23 - this->timer) * 7281.778f) + 10922.667f;
            this->actor.shape.rot.y = (28 - this->timer) * (f32)0x1000;
        } else {
            Actor_SetScale(&this->actor, (((28 - this->timer) * 0.1f) + 1.0f) * 0.01f);
            Math_Vec3f_Copy(&this->reviveScale, &gZeroVec3f);
            this->actor.shape.rot.y = (28 - this->timer) * (f32)0x1000;
        }

        if (this->timer == 21) {
            this->collider.base.ocFlags1 |= OC1_ON;
        }

        this->reviveRotY += this->actor.home.rot.y;
        this->actor.shape.rot.y += this->actor.home.rot.y;
    }
}
