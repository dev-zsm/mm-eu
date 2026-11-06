// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_80939EF4(ObjBombiwa* this, PlayState* play) {
    s32 pad;
    s32 params = OBJBOMBIWA_GET_100(&this->actor);
    ObjBombiwaStruct2* sp28 = &ref_D_8093A998[params];

    if (this->collider.base.acFlags & AC_HIT) {
        this->unk_202 = 5;
    }

    if (sp28->unk_0C(&this->actor)) {
        Flags_SetSwitch(play, OBJBOMBIWA_GET_SWITCH_FLAG(&this->actor));
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 80, NA_SE_EV_WALL_BROKEN);
        if (OBJBOMBIWA_GET_8000(&this->actor)) {
            Audio_PlaySfx(NA_SE_SY_CORRECT_CHIME);
        }

        if (params == OBJBOMBIWA_100_0) {
            ref_func_80939794(this, play);
            Actor_Kill(&this->actor);
        } else {
            ref_func_80939994(play, &this->actor.world.pos);
            this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            ref_func_8093A080(this);
        }
    } else {
        this->collider.base.acFlags &= ~AC_HIT;

        if (this->actor.xzDistToPlayer < 1400.0f) {
            if (this->unk_202 > 0) {
                this->unk_202--;
                if (this->unk_202 == 0) {
                    this->collider.base.colMaterial = COL_MATERIAL_HARD;
                } else {
                    this->collider.base.colMaterial = COL_MATERIAL_NONE;
                }
            }
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        }
    }
}
