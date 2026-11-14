// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tsn.h"

void func_8000113C(Actor* thisx, PlayState* play) {
    s32 pad;
    EnTsn* this = (EnTsn*)thisx;

    this->actionFunc(this, play);

    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 20.0f, 25.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
    SkelAnime_Update(&this->skelAnime);

    if (this->flags & ENTSN_LOOK_AT_PLAYER) {
        Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&this->headRot.x, 0, 6, 0x1838, 0x64);
        Math_SmoothStepToS(&this->headRot.y, 0, 6, 0x1838, 0x64);
        Math_SmoothStepToS(&this->torsoRot.x, 0, 6, 0x1838, 0x64);
        Math_SmoothStepToS(&this->torsoRot.y, 0, 6, 0x1838, 0x64);
    }

    if (DECR(this->blinkTimer) == 0) {
        this->blinkTimer = Rand_S16Offset(60, 60);
    }

    if ((this->blinkTimer == 1) || (this->blinkTimer == 3)) {
        this->eyeIndex = FISHERMAN_EYE_CLOSED;
    } else {
        this->eyeIndex = FISHERMAN_EYE_OPEN;
    }
}
