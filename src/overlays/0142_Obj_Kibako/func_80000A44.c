// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ObjKibako_Idle(ObjKibako* this, PlayState* play) {
    s32 pad;
    s32 pad1;

    if (Actor_HasParent(&this->actor, play)) {
        ObjKibako_SetupHeld(this);
        this->actor.room = -1;
        this->actor.colChkInfo.mass = 120;
        if (ref_func_800A817C(KIBAKO_COLLECTIBLE_ID(&this->actor))) {
            ObjKibako_SpawnCollectible(this, play);
        }

        
        
        Player_PlaySfx((Player*)&this->actor, NA_SE_PL_PULL_UP_WOODBOX);
    } else if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) && (this->actor.depthInWater > 19.0f)) {
        ObjKibako_WaterBreak(this, play);
        ObjKibako_SpawnCollectible(this, play);
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
        Actor_Kill(&this->actor);
    } else if (this->collider.base.acFlags & AC_HIT) {
        ObjKibako_AirBreak(this, play);
        ObjKibako_SpawnCollectible(this, play);
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        Actor_Kill(&this->actor);
    } else {
        Actor_MoveWithGravity(&this->actor);
        ref_func_809262BC(this);
        Actor_UpdateBgCheckInfo(play, &this->actor, 18.0f, 15.0f, 0.0f,
                                UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_40);

        if (!(this->collider.base.ocFlags1 & OC1_TYPE_PLAYER) && (this->actor.xzDistToPlayer > 28.0f)) {
            this->collider.base.ocFlags1 |= OC1_TYPE_PLAYER;
        }

        if ((this->actor.colChkInfo.mass != MASS_IMMOVABLE) &&
            (Math3D_Vec3fDistSq(&this->actor.world.pos, &this->actor.prevPos) < 0.01f)) {
            this->actor.colChkInfo.mass = MASS_IMMOVABLE;
        }

        this->collider.base.acFlags &= ~AC_HIT;

        if (KIBAKO_BOMBER_CAN_HIDE_IN_BOX(&this->actor)) {
            Collider_UpdateCylinder(&this->actor, &this->collider);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

            if (this->actor.xzDistToPlayer < 800.0f) {
                CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
                ref_func_80926318(this, play);
            }
        } else {
            if (this->actor.xzDistToPlayer < 800.0f) {
                Collider_UpdateCylinder(&this->actor, &this->collider);
                CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);

                if (this->actor.xzDistToPlayer < 180.0f) {
                    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
                    ref_func_80926318(this, play);
                }
            }
        }
    }
}
