// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount2.h"

void EnEncount2_Update(Actor* thisx, PlayState* play) {
    EnEncount2* this = (EnEncount2*)thisx;
    s32 pad;

    DECR(this->deathTimer);

    this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;
    Actor_SetFocus(&this->dyna.actor, 30.0f);
    Actor_SetScale(&this->dyna.actor, this->scale);
    this->actionFunc(this, play);
    Actor_MoveWithGravity(&this->dyna.actor);
    EnEncount2_UpdateEffects(this, play);

    if (!this->isPopped) {
        Collider_UpdateSpheresElement(&this->collider, 0, &this->dyna.actor);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
