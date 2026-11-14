// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_80002568(Actor* thisx, PlayState* play) {
    EnKakasi* this = (EnKakasi*)thisx;
    s32 pad;

    SkelAnime_Update(&this->skelAnime);
    if (this->picto.actor.draw != NULL) {
        EnKakasi_CheckAnimationSfx(this);
    }

    this->picto.actor.world.rot.y = this->picto.actor.shape.rot.y;
    DECR(this->postTeachTimer);
    DECR(this->unk204);

    if (this->unkState196 != 5) {
        if ((this->unk1BC.x != 0.0f) || (this->unk1BC.z != 0.0f)) {
            Math_Vec3f_Copy(&this->picto.actor.focus.pos, &this->unk1BC);
            this->picto.actor.focus.pos.y += 10.0f;
            if (this->subCamId == SUB_CAM_ID_DONE) {
                Math_Vec3s_Copy(&this->picto.actor.focus.rot, &this->picto.actor.world.rot);
            } else {
                Math_Vec3s_Copy(&this->picto.actor.focus.rot, &this->picto.actor.home.rot);
            }
        }
    } else {
        Actor_SetFocus(&this->picto.actor, this->unkHeight);
    }

    this->actionFunc(this, play);
    Actor_MoveWithGravity(&this->picto.actor);
    Actor_UpdateBgCheckInfo(play, &this->picto.actor, 50.0f, 50.0f, 100.0f,
    UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 | UPDBGCHECKINFO_FLAG_10);
    if (this->picto.actor.draw != NULL) {
        Collider_UpdateCylinder(&this->picto.actor, &this->collider);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
