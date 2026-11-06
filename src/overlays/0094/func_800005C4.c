// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_m_thunder.h"

void EnMThunder_Charge(EnMThunder* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Actor* child = this->actor.child;

    this->unk1B0 = player->unk_B08;
    this->actor.world.pos = player->bodyPartsPos[PLAYER_BODYPART_WAIST];
    this->actor.shape.rot.y = player->actor.shape.rot.y + 0x8000;

    if (!this->isCharging && (player->unk_B08 >= 0.1f)) {
        if ((gSaveContext.magicState != MAGIC_STATE_IDLE) ||
            ((ENMTHUNDER_GET_MAGIC_COST(&this->actor) != 0) &&
             !Magic_Consume(play, ENMTHUNDER_GET_MAGIC_COST(&this->actor), MAGIC_CONSUME_WAIT_PREVIEW))) {
            EnMThunder_Spin_AttackNoMagic(this, play);
            this->actionFunc = EnMThunder_Spin_AttackNoMagic;
            this->chargingAlpha = 0;
            this->adjustLightsArg1 = 0.0f;
            this->lightColorFrac = 0.0f;
            return;
        }
        this->isCharging = true;
    }

    if (player->unk_B08 >= 0.1f) {
        Rumble_Request(0.0f, (s32)(player->unk_B08 * 150.0f), 2, (s32)(player->unk_B08 * 150.0f));
    }

    if (player->stateFlags2 & PLAYER_STATE2_20000) {
        if ((child != NULL) && (child->update != NULL)) {
            child->parent = NULL;
        }

        if (player->unk_B08 <= 0.15f) {
            if ((player->unk_B08 >= 0.1f) && (player->meleeWeaponAnimation >= PLAYER_MWA_SPIN_ATTACK_1H)) {
                AudioSfx_PlaySfx(NA_SE_IT_ROLLING_CUT, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                                 &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
                AudioSfx_PlaySfx(NA_SE_IT_SWORD_SWING_HARD, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                                 &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
            }
            Actor_Kill(&this->actor);
            return;
        }

        player->stateFlags2 &= ~PLAYER_STATE2_20000;

        if (ENMTHUNDER_GET_MAGIC_COST(&this->actor) != 0) {
            gSaveContext.magicState = MAGIC_STATE_CONSUME_SETUP;
        }

        if (player->unk_B08 < 0.85f) {
            this->collider.elem.atDmgInfo.damage = sDamages[this->type];
            this->subtype = ENMTHUNDER_SUBTYPE_SPIN_REGULAR;
            if (this->type == ENMTHUNDER_TYPE_GREAT_FAIRYS_SWORD) {
                this->scaleTarget = 4;
            } else if (this->type == ENMTHUNDER_TYPE_GILDED_SWORD) {
                this->scaleTarget = 3;
            } else {
                this->scaleTarget = 2;
            }
        } else {
            this->collider.elem.atDmgInfo.damage = sDamages[this->type + ENMTHUNDER_TYPE_MAX];
            this->subtype = ENMTHUNDER_SUBTYPE_SPIN_GREAT;
            if (this->type == ENMTHUNDER_TYPE_GREAT_FAIRYS_SWORD) {
                this->scaleTarget = 6;
            } else if (this->type == ENMTHUNDER_TYPE_GILDED_SWORD) {
                this->scaleTarget = 4;
            } else {
                this->scaleTarget = 3;
            }
        }

        if (player->meleeWeaponAnimation < PLAYER_MWA_SPIN_ATTACK_1H) {
            this->subtype += ENMTHUNDER_SUBTYPE_SWORDBEAM_GREAT;
            this->actionFunc = EnMThunder_SwordBeam_Attack;
            this->timer = 1;
        } else {
            this->actionFunc = EnMThunder_Spin_Attack;
            this->timer = 8;
        }

        AudioSfx_PlaySfx(sChargingSfxIds[this->subtype], &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                         &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);

        this->lightColorFrac = 1.0f;

        return;
    }

    if (!(player->stateFlags1 & PLAYER_STATE1_CHARGING_SPIN_ATTACK)) {
        if (this->actor.child != NULL) {
            this->actor.child->parent = NULL;
        }
        Actor_Kill(&this->actor);
        return;
    }

    if (player->unk_B08 > 0.15f) {
        this->chargingAlpha = 255;
        if (this->actor.child == NULL) {
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EFF_DUST, this->actor.world.pos.x,
                               this->actor.world.pos.y, this->actor.world.pos.z, 0, this->actor.shape.rot.y, 0,
                               EFF_DUST_TYPE_SPIN_ATTACK_CHARGE);
        }
        this->adjustLightsArg1 += (((player->unk_B08 - 0.15f) * 1.5f) - this->adjustLightsArg1) * 0.5f;
    } else if (player->unk_B08 > .1f) {
        this->chargingAlpha = (s32)((player->unk_B08 - .1f) * 255.0f * 20.0f);
        this->lightColorFrac = (player->unk_B08 - .1f) * 10.0f;
    } else {
        this->chargingAlpha = 0;
    }

    if (player->unk_B08 > 0.85f) {
        Audio_PlaySfx_SwordCharge(&player->actor.projectedPos, 2);
    } else if (player->unk_B08 > 0.15f) {
        Audio_PlaySfx_SwordCharge(&player->actor.projectedPos, 1);
    } else if (player->unk_B08 > 0.1f) {
        Audio_PlaySfx_SwordCharge(&player->actor.projectedPos, 0);
    }

    if (Play_InCsMode(play)) {
        Actor_Kill(&this->actor);
    }
}
