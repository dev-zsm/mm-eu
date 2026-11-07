// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_estone.h"

void EnEstone_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnEstone* this = (EnEstone*)thisx;

    DECR(this->timer);

    this->actionFunc(this, play);

    this->rot.x -= this->rotVel.x;
    this->rot.y -= this->rotVel.y;
    this->rot.z -= this->rotVel.z;

    Actor_MoveWithGravity(&this->actor);
    if ((this->timer == 0) && !this->inactive) {
        Actor_UpdateBgCheckInfo(play, &this->actor, 50.0f, 50.0f, 100.0f,
                                UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 | UPDBGCHECKINFO_FLAG_10);
    }
    if (!this->inactive) {
        Collider_UpdateCylinder(&this->actor, &this->collider);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
    EnEstone_UpdateEffects(this, play);
}
