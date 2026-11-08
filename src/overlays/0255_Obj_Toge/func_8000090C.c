// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

void ObjToge_Update(Actor* thisx, PlayState* play) {
    ObjToge* this = (ObjToge*)thisx;
    ColliderCylinder* collider = &this->collider;

    if (this->collider.base.acFlags & AC_HIT) {
        if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x1000) {
            ref_func_809A43A8(this, play);
            Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_BLUE, 250, COLORFILTER_BUFFLAG_OPA, 250);
        }
        collider->base.acFlags &= ~AC_HIT;
    }

    if (this->actor.colorFilterTimer == 0) {
        if (this->collider.base.ocFlags2 & OC2_HIT_PLAYER) {
            ref_func_800B8DD4(play, &this->actor, 6.0f, this->actor.yawTowardsPlayer, 6.0f, 4);
        }

        this->actionFunc(this, play);

        Collider_UpdateCylinder(&this->actor, &this->collider);
        if (this->actor.xzDistToPlayer < 1000.0f) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        }
    }

    if ((this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) || (this->actor.xzDistToPlayer < 300.0f)) {
        CollisionCheck_SetOC(play, &play->colChkCtx, &collider->base);
    } else {
        this->collider.base.ocFlags1 &= ~OC1_HIT;
        this->collider.base.ocFlags2 &= ~OC2_HIT_PLAYER;
    }
}
