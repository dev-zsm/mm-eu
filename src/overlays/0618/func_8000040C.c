// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombal.h"

void EnBombal_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    EnBombal* this = (EnBombal*)thisx;

    if (this->timer != 0) {
        this->timer--;
    }

    this->actor.shape.rot.y = this->actor.world.rot.y;

    Actor_SetFocus(&this->actor, 30.0f);
    Actor_SetScale(&this->actor, this->scale);

    this->actionFunc(this, play);

    Actor_MoveWithGravity(&this->actor);
    EnBombal_UpdateEffects(this, play);

    if (!this->isPopped) {
        Collider_UpdateCylinder(&this->actor, &this->collider);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
