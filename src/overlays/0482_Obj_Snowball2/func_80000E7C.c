// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B39C9C(ObjSnowball2* this, PlayState* play) {
    s32 pad;
    s32 sp38 = (this->collider.base.acFlags & AC_HIT) != 0;
    s32 pad2;

    if (sp38) {
        this->collider.base.acFlags &= ~AC_HIT;
    }

    if (Actor_HasParent(&this->actor, play)) {
        this->actor.room = -1;
        this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        if (ref_func_800A817C(ENOBJSNOWBALL2_GET_3F(&this->actor))) {
            ref_func_80B38E88(this, play);
        }
        ref_func_80B38EFC(this, play);
        Player_PlaySfx(GET_PLAYER(play), NA_SE_PL_PULL_UP_SNOWBALL);
        ref_func_80B39F60(this);
    } else if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) &&
               ((this->actor.shape.yOffset * this->actor.scale.y) < this->actor.depthInWater)) {
        ref_func_80B3A498(this);
    } else if (sp38 && (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x0583FFBC)) {
        ref_func_80B38E88(this, play);
        ref_func_80B39108(this, play);
        ref_func_80B39B5C(this, play);
        Actor_Kill(&this->actor);
        return;
    } else {
        if (sp38 && (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 2)) {
            ref_func_80B39908(this, play);
        }

        if (this->unk_1AD == 0) {
            Actor_MoveWithGravity(&this->actor);
            Actor_UpdateBgCheckInfo(play, &this->actor, 15.0f, 15.0f, 0.0f,
                                    UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_40);
            if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) &&
                (DynaPoly_GetActor(&play->colCtx, this->actor.floorBgId) == NULL)) {
                this->unk_1AD = 1;
                this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            }
        }

        if (this->actor.xzDistToPlayer < 800.0f) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            if (this->actor.xzDistToPlayer < 150.0f) {
                CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
                if (this->actor.xzDistToPlayer < 100.0f) {
                    if (ABS_ALT(BINANG_SUB(this->actor.yawTowardsPlayer, GET_PLAYER(play)->actor.world.rot.y)) >=
                        0x5556) {
                        Actor_OfferGetItem(&this->actor, play, GI_NONE, 36.0f, 30.0f);
                    }
                }
            }
        }
    }
}
