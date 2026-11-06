// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void ref_func_809CEBC0(BgSpdweb* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 sp58;
    f32 temp_f10;
    f32 temp_f18;
    ColliderTrisElement* trisElem;
    s32 i;
    Vec3f sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    if (this->collider.base.acFlags & AC_HIT) {
        for (i = 0; i < ARRAY_COUNT(this->colliderElements); i++) {
            trisElem = &this->collider.elements[i];
            if (trisElem->base.acElemFlags & ACELEM_HIT) {
                Math_Vec3s_ToVec3f(&this->dyna.actor.home.pos, &trisElem->base.acDmgInfo.hitPos);
                break;
            }
        }

        if (i == ARRAY_COUNT(this->colliderElements)) {
            this->dyna.actor.home.pos.x =
                ((90.0f * Math_SinS(this->dyna.actor.shape.rot.x)) * Math_SinS(this->dyna.actor.shape.rot.y)) +
                this->dyna.actor.world.pos.x;
            this->dyna.actor.home.pos.y =
                (90.0f * Math_CosS(this->dyna.actor.shape.rot.x)) + this->dyna.actor.world.pos.y;
            this->dyna.actor.home.pos.z =
                ((90.0f * Math_SinS(this->dyna.actor.shape.rot.x)) * Math_CosS(this->dyna.actor.shape.rot.y)) +
                this->dyna.actor.world.pos.z;
        }
        ref_func_809CEE74(this);
    } else if ((player->heldItemAction == PLAYER_IA_DEKU_STICK) && (player->unk_B28 != 0)) {
        Math_Vec3f_Diff(&player->meleeWeaponInfo[0].tip, &this->dyna.actor.world.pos, &sp3C);
        sp38 = Math_SinS(-this->dyna.actor.shape.rot.x);
        sp34 = Math_CosS(-this->dyna.actor.shape.rot.x);
        sp30 = Math_SinS(-this->dyna.actor.shape.rot.y);
        sp2C = Math_CosS(-this->dyna.actor.shape.rot.y);

        temp_f18 = ((sp3C.x * sp38 * sp30) + (sp3C.y * sp34)) - (sp3C.z * sp38 * sp2C);
        sp58 = (-sp3C.x * sp34 * sp30) + (sp3C.y * sp38) + (sp3C.z * sp34 * sp2C);
        temp_f10 = (sp3C.x * sp2C) + (sp3C.z * sp30);

        if ((fabsf(temp_f10) < 70.0f) && (fabsf(sp58) < 10.0f) && (temp_f18 < 160.0f) && (temp_f18 > 20.0f)) {
            Math_Vec3f_Copy(&this->dyna.actor.home.pos, &player->meleeWeaponInfo[0].tip);
            ref_func_809CEE74(this);
        }
    }

    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
