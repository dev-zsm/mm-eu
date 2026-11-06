// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B3A13C(ObjSnowball2* this, PlayState* play) {
    s32 pad;
    s32 sp38 = (this->collider.base.atFlags & AT_HIT) != 0;
    s32 sp34 = (this->collider.base.ocFlags1 & OC1_HIT) != 0;
    s32 sp30;

    if (sp38) {
        this->collider.base.atFlags &= ~AT_HIT;
    }

    if (sp34) {
        this->collider.base.ocFlags1 &= ~OC1_HIT;
    }

    if (this->unk_1AC > 0) {
        this->unk_1AC--;
    }

    ref_func_80B39B28(this, play);

    if ((((this->actor.bgCheckFlags & (BGCHECKFLAG_GROUND | BGCHECKFLAG_WALL)) || sp38) &&
         !(this->actor.bgCheckFlags & BGCHECKFLAG_WATER)) ||
        (this->unk_1AC <= 0)) {
        ref_func_80B38E88(this, play);
        ref_func_80B39108(this, play);
        ref_func_80B39B5C(this, play);
        Actor_Kill(&this->actor);
        return;
    }

    sp30 = false;
    if (this->actor.bgCheckFlags & (BGCHECKFLAG_WATER | BGCHECKFLAG_WATER_TOUCH)) {
        if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) || (this->actor.speed > 3.0f)) {
            if (this->actor.depthInWater < (1200.0f * this->actor.scale.y)) {
                ref_func_80B39470(&this->actor, play);
                ref_func_80B395EC(&this->actor, play);
            }
            if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
                Actor_PlaySfx(&this->actor, NA_SE_EV_BOMB_DROP_WATER);
            }
        } else if ((((play->gameplayFrames % 16) == 0) || ((Rand_Next() >> 0x10) == 0)) &&
                   (this->actor.depthInWater < (1200.0f * this->actor.scale.y))) {
            ref_func_80B395EC(&this->actor, play);
        }

        ref_func_80B39834(&this->actor, play);
        this->unk_1A8 >>= 1;
        this->unk_1AA >>= 1;

        if (sp34) {
            this->actor.speed *= 0.8f;
        } else {
            this->actor.speed *= 0.65f;
        }
        this->actor.velocity.y *= 0.27f;
        this->actor.gravity *= 0.27f;
        if (this->actor.speed < 0.4f) {
            sp30 = true;
        }
    } else {
        if (sp34) {
            this->actor.speed *= 0.8f;
        } else {
            this->actor.speed *= 0.96f;
        }
        this->actor.velocity.y *= 0.96f;
    }

    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 15.0f, 15.0f, 0.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_40);
    this->actor.shape.rot.x += this->unk_1A8;
    this->actor.shape.rot.y += this->unk_1AA;
    ref_func_80B38E20(this);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    if (sp30) {
        ref_func_80B3A498(this);
    } else {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    }
}
