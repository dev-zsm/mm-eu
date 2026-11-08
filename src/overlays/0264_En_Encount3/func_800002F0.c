// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount3.h"

void EnEncount3_Update(Actor* thisx, PlayState* play2) {
    EnEncount3* this = (EnEncount3*)thisx;
    f32 new_var;
    PlayState* play = play2;
    Player* player = GET_PLAYER(play);
    f32 sp3C;
    f32 sp38;

    this->actionFunc(this, play);
    if (this->actionFunc == ref_func_809AD194) {
        new_var = this->unk16C * 0.52f;
        if (new_var < this->actor.xzDistToPlayer) {
            this->unk178 = ((this->unk16C * 0.03125f) * 0.001f) + 0.1f;
        } else {
            this->unk178 = 0.06f;
        }

        if (((this->unk16C + 50.0f) + BREG(0)) < this->actor.xzDistToPlayer) {
            if (this->actionFunc == ref_func_809AD194) {
                this->unk148 = 0;
                this->unk178 = 0.0f;
                ref_D_809AD810 = false;
                if (((this->child != NULL) && (this->child->update != NULL)) && (this->child->colChkInfo.health > 0)) {
                    Actor_Kill(this->child);
                    this->child = NULL;
                }
                ref_func_809AD058(this);
            }
        } else if (this->unk16C < this->actor.xzDistToPlayer) {
            s16 i;

            for (i = 0; i < PLAYER_BODYPART_MAX; i++) {
                player->bodyFlameTimers[i] = Rand_S16Offset(0, 200);
            }
            player->bodyIsBurning = true;

            sp3C = this->actor.world.pos.x - player->actor.world.pos.x;
            sp38 = this->actor.world.pos.z - player->actor.world.pos.z;
            if (!Play_InCsMode(play)) {
                ref_func_800B8D50(play, &this->actor, 10.0f, Math_Atan2S_XY(sp38, sp3C), 0.0f, 1);
            }
        }
        this->child->colChkInfo = this->child->colChkInfo; 
    }

    this->unk168 = this->unk16C;
    this->unk168 /= 7666.0f;
    if (this->actionFunc != ref_func_809AD194) {
        Math_ApproachZeroF(&this->unk170, 0.3f, 10.0f);
        Math_ApproachZeroF(&this->unk160, 0.3f, 5.0f);
        if (this->unk160 < 1.0f) {
            play->unk_18880 = false;
        }
    } else if (this->unk148 != 0) {
        Math_ApproachF(&this->unk170, 255.0f, 0.4f, 10.0f);
        Math_ApproachF(&this->unk160, 60.0f, 0.3f, 5.0f);
    }
    Math_ApproachF(&this->unk174, this->unk178, 0.3f, 0.03f);

    this->unk164 = this->unk160 / 60.0f;
    if (this->unk164 != 0.0f) {
        play->envCtx.adjLightSettings.fogNear = (960 - play->envCtx.lightSettings.fogNear) * this->unk164;
        play->envCtx.adjLightSettings.fogColor[0] = (40.0f - play->envCtx.lightSettings.fogColor[0]) * this->unk164;
        play->envCtx.adjLightSettings.fogColor[1] = (10.0f - play->envCtx.lightSettings.fogColor[1]) * this->unk164;
        play->envCtx.adjLightSettings.fogColor[2] = (0.0f - play->envCtx.lightSettings.fogColor[2]) * this->unk164;
    }
}
