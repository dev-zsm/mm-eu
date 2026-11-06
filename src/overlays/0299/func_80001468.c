// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1C838(ObjFlowerpot* this, PlayState* play) {
    s32 pad;

    if (Actor_HasParent(&this->actor, play)) {
        ref_func_80A1CBF8(this);
        this->actor.room = -1;
        this->actor.colChkInfo.mass = 180;
        this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        if (ref_func_800A817C(ENOBJFLOWERPOT_GET_3F(&this->actor))) {
            ref_func_80A1B914(this, play);
        }

        
        
        Player_PlaySfx((Player*)&this->actor, NA_SE_PL_PULL_UP_POT);
    } else if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) && (this->actor.depthInWater > 19.0f)) {
        if (!(this->unk_1EA & 2)) {
            ref_func_80A1B914(this, play);
            ref_func_80A1C328(this, play);
            ref_func_80A1B9CC(this, play);
            this->unk_1EA |= 2;
        }
        ref_func_80A1BD80(this, play);
        ref_func_80A1B994(this, play);
        Actor_Kill(&this->actor);
    } else if ((this->collider.elements[0].base.acElemFlags & ACELEM_HIT) &&
               (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x058BFFBC)) {
        if (!(this->unk_1EA & 2)) {
            ref_func_80A1B914(this, play);
            ref_func_80A1C0FC(this, play);
            ref_func_80A1B9CC(this, play);
            this->unk_1EA |= 2;
        }
        ref_func_80A1BA44(this, play);
        ref_func_80A1B994(this, play);
        Actor_Kill(&this->actor);
    } else {
        if (this->collider.elements[1].base.acElemFlags & ACELEM_HIT) {
            if (!(this->unk_1EA & 2)) {
                this->unk_1EA |= 2;
                this->collider.elements[1].base.acElemFlags &= ~ACELEM_ON;
                ref_func_80A1C0FC(this, play);
                ref_func_80A1B914(this, play);
                ref_func_80A1B9CC(this, play);
            }
        }

        if (this->unk_1EA & 1) {
            Actor_MoveWithGravity(&this->actor);
            ref_func_80A1C5E8(this, play);
            if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
                if (this->actor.colChkInfo.mass == MASS_IMMOVABLE) {
                    if (DynaPoly_GetActor(&play->colCtx, this->actor.floorBgId) == NULL) {
                        this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
                        this->unk_1EA &= ~0x1;
                    }
                } else if (Math3D_Vec3fDistSq(&this->actor.world.pos, &this->actor.prevPos) < 0.01f) {
                    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
                }
            }
        }

        if (!(this->collider.base.ocFlags1 & OC1_TYPE_PLAYER) && (this->actor.xzDistToPlayer > 28.0f)) {
            this->collider.base.ocFlags1 |= OC1_TYPE_PLAYER;
        }

        this->collider.base.acFlags &= ~AC_HIT;

        if (this->actor.xzDistToPlayer < 600.0f) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);

            if (this->actor.xzDistToPlayer < 180.0f) {
                CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

                if (this->actor.xzDistToPlayer < 100.0f) {
                    s16 temp_v0_3 = this->actor.yawTowardsPlayer - GET_PLAYER(play)->actor.world.rot.y;

                    if (ABS_ALT(temp_v0_3) >= 0x5556) {
                        Actor_OfferGetItem(&this->actor, play, GI_NONE, 36.0f, 30.0f);
                    }
                }
            }
        }
    }
}
