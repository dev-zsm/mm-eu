// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B04350(ObjSnowball* this, PlayState* play) {
    s32 pad;
    s32 flag = (this->collider.base.acFlags & AC_HIT) != 0;

    if (flag) {
        this->collider.base.acFlags &= ~AC_HIT;
    }

    if (flag && (this->unk_211 == 0) &&
        (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags &
         (0x80000000 | 0x4000 | 0x800 | 0x400 | 0x100 | 0x8))) {
        this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        if (this->actor.home.rot.y == 1) {
            this->actor.flags &= ~(ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_FRIENDLY);
        }

        if (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x4000) {
            this->unk_20A = 1;
        } else {
            if (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x800) {
                this->unk_210 = 1;
            }
            this->unk_20A = 0;
        }

        if (this->actor.csId <= CS_ID_NONE) {
            ref_func_80B03FF8(this, play);
            if (this->unk_20A == 0) {
                ref_func_80B04608(this, play);
            } else {
                ref_func_80B046E4(this, play);
            }
        } else {
            ref_func_80B04540(this, play);
        }
        return;
    }

    if (flag &&
        !(this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & (0x10000 | 0x2000 | 0x1000 | 0x800 | 0x20))) {
        if (this->unk_209 <= 0) {
            ref_func_80B02EE4(this, play);
            if (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x1000000) {
                this->unk_209 = 25;
            } else {
                this->unk_209 = 10;
            }
            Actor_PlaySfx(&this->actor, NA_SE_IT_REFLECTION_SNOW);
        }
    }

    if (this->unk_209 > 0) {
        this->unk_209--;
    }

    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
