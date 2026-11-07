// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void ref_func_809CE4C8(BgSpdweb* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f sp40;
    ColliderTrisElement* trisElem;
    s16 sp3A;
    s32 i;
    f32 temp_f12;

    sp40.x = this->dyna.actor.world.pos.x;
    sp40.y = this->dyna.actor.world.pos.y - 50.0f;
    sp40.z = this->dyna.actor.world.pos.z;
    sp3A = player->fallDistance;

    if (Player_IsBurningStickInRange(play, &sp40, 70.0f, 50.0f)) {
        this->dyna.actor.home.pos.x = player->meleeWeaponInfo[0].tip.x;
        this->dyna.actor.home.pos.z = player->meleeWeaponInfo[0].tip.z;
        ref_func_809CEE74(this);
        return;
    }

    if (this->collider.base.acFlags & AC_HIT) {
        for (i = 0; i < 2; i++) {
            trisElem = &this->collider.elements[i];
            if (trisElem->base.acElemFlags & ACELEM_HIT) {
                if (this->collider.elements[i].base.acHitElem->atDmgInfo.dmgFlags & 0x800) {
                    Math_Vec3s_ToVec3f(&this->dyna.actor.home.pos, &trisElem->base.acDmgInfo.hitPos);
                    ref_func_809CEE74(this);
                    return;
                }

                if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
                    sp3A = 300;
                    break;
                }
            }
        }
    }

    if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        temp_f12 = 2.0f * sqrtf(CLAMP_MIN(sp3A, 0));
        if ((this->unk_164 < temp_f12) && (temp_f12 > 2.0f)) {
            this->unk_164 = temp_f12;
            this->unk_162 = 12;
            if (sp3A > 50) {
                player->stateFlags1 |= PLAYER_STATE1_20;
                this->unk_161 = 1;
            }
        } else if (player->actor.speed != 0.0f) {
            this->unk_164 = CLAMP_MIN(this->unk_164, 2.0f);
        }
    }

    if (this->unk_162 != 0) {
        this->unk_162--;
    }

    this->dyna.actor.world.pos.y =
        (Math_SinF(this->unk_162 * (M_PIf / 6)) * this->unk_164) + this->dyna.actor.home.pos.y;
    Math_ApproachZeroF(&this->unk_164, 1.0f, 0.8f);

    if (this->unk_162 == 4) {
        if ((this->unk_161 != 0) || (DynaPolyActor_IsPlayerOnTop(&this->dyna) && (this->unk_164 > 2.0f))) {
            player->actor.velocity.y = this->unk_164 * 0.7f;
            player->fallStartHeight = (SQ(this->unk_164) * 0.15f) + this->dyna.actor.world.pos.y;
            this->unk_161 = 0;
            player->stateFlags1 &= ~PLAYER_STATE1_20;
        }
    } else if (this->unk_162 == 11) {
        if (this->unk_164 > 3.0f) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WEB_VIBRATION);
        } else {
            AudioSfx_StopById(NA_SE_EV_WEB_VIBRATION);
        }
    }

    if (this->unk_162 == 0) {
        this->unk_162 = 12;
    }

    ref_func_809CE15C(this);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
