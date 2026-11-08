// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80941A10(EnGoroiwa* this, PlayState* play) {
    static EnGoroiwaUnkFunc ref_D_80942E94[] = {
        ref_func_8093F498,
        ref_func_8093F34C,
    };
    static u16 ref_D_80942E9C[][2] = {
        { NA_SE_EV_BIGBALL_ROLL - SFX_FLAG, NA_SE_EV_BIGBALL_ROLL_SR - SFX_FLAG },
        { NA_SE_EV_BIGBALL_ROLL_2 - SFX_FLAG, NA_SE_EV_BIGBALL_ROLL_SR_2 - SFX_FLAG },
        { NA_SE_EV_BIGBALL_ROLL_3 - SFX_FLAG, NA_SE_EV_BIGBALL_ROLL_SR_3 - SFX_FLAG },
        { NA_SE_EV_BIGBALL_ROLL - SFX_FLAG, NA_SE_EV_BIGBALL_ROLL_SR - SFX_FLAG },
    };
    s32 pad;
    Player* player = GET_PLAYER(play);
    s32 sp44 = ENGOROIWA_GET_400(&this->actor);
    s32 sp40 = ENGOROIWA_GET_3000(&this->actor);
    s16 y;
    s32 pad2;

    if (!ref_func_8094156C(this, play)) {
        if ((this->collider.base.atFlags & AT_HIT) && !(player->stateFlags3 & PLAYER_STATE3_80000)) {
            s32 sp34 = this->actor.home.rot.z & 3;

            if (sp34 == 2) {
                ref_func_80940090(this, play);
                if (sp40 == ENGOROIWA_3000_2) {
                    ref_func_8093E8A0(this);
                    ref_func_8093E91C(this);
                }
                ref_func_80941274(this, play);
                ref_func_8093EDD8(this, play);
                ref_func_8093EE64(this, 0);
                ref_func_8093EEBC(this);
            } else {
                this->unk_1E5 &= ~8;
                y = this->actor.yawTowardsPlayer - this->actor.world.rot.y;
                if ((y > -0x4000) && (y < 0x4000)) {
                    this->unk_1E5 |= 8;
                    if (sp44 || (sp34 != 1)) {
                        ref_func_8093EDB0(this);
                    }
                }
            }

            ref_func_800B8D50(play, &this->actor, 2.0f, this->actor.yawTowardsPlayer, 0.0f, 0);

            if (sp34 == 2) {
                ref_func_80941EB4(this);
            } else if (!sp44) {
                ref_func_80941EB4(this);
            } else {
                ref_func_80941DB4(this);
            }

            Player_PlaySfx(player, NA_SE_PL_BODY_HIT);

            if ((sp34 == 1) || (sp34 == 2)) {
                this->unk_1CC = 50;
            }
        } else {
            if (ref_D_80942E94[sp44](this)) {
                s32 sp30 = ENGOROIWA_GET_300(&this->actor);

                if ((sp30 == ENGOROIWA_300_1) && ((this->unk_1D8 == 0) || (this->unk_1D8 == this->unk_1D4))) {
                    ref_func_80940090(this, play);
                    ref_func_80941274(this, play);
                }

                if (((sp30 == ENGOROIWA_300_1) || (sp30 == ENGOROIWA_300_0)) && (sp40 == ENGOROIWA_3000_2) &&
                    ((this->unk_1D8 == 0) || (this->unk_1D8 == this->unk_1D4))) {
                    ref_func_8093E8A0(this);
                    ref_func_8093E91C(this);
                }

                ref_func_8093FC00(this);

                if ((sp30 == ENGOROIWA_300_3) && ((this->unk_1D6 == 0) || (this->unk_1D6 == this->unk_1D4))) {
                    ref_func_80941EB4(this);
                } else if (!sp44 && (this->unk_1D6 != 0) && (this->unk_1D6 != this->unk_1D4)) {
                    sp30 = ref_func_8093EEDC(this);
                    if (sp30 > 0) {
                        ref_func_80941F54(this);
                    } else if (sp30 < 0) {
                        ref_func_80942084(this);
                    } else {
                        ref_func_809419D0(this);
                    }
                } else {
                    ref_func_809419D0(this);
                }
            }
        }

        if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
            Actor_PlaySfx(&this->actor, ref_D_80942E9C[this->unk_1E4][this->actor.home.rot.x & 1]);
        }
    }
}
