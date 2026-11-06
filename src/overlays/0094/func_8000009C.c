// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_m_thunder.h"

void EnMThunder_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnMThunder* this = (EnMThunder*)thisx;
    Player* player = GET_PLAYER(play);

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->type = ENMTHUNDER_GET_TYPE(&this->actor);
    Lights_PointNoGlowSetInfo(&this->lightInfo, this->actor.world.pos.x, this->actor.world.pos.y,
                              this->actor.world.pos.z, 255, 255, 255, 0);
    this->lightNode = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);

    if (this->type == ENMTHUNDER_TYPE_UNK) {
        EnMThunder_UnkType_Setup(this, play);
        return;
    }

    this->collider.dim.radius = 0;
    this->collider.dim.height = 40;
    this->collider.dim.yShift = -20;
    this->timer = 8;
    this->scroll = 0.0f;
    this->actor.world.pos = player->bodyPartsPos[PLAYER_BODYPART_WAIST];
    this->lightColorFrac = 0.0f;
    this->adjustLightsArg1 = 0.0f;
    this->actor.shape.rot.y = player->actor.shape.rot.y + 0x8000;
    this->actor.shape.rot.x = -this->actor.world.rot.x;
    this->actor.room = -1;
    Actor_SetScale(&this->actor, 0.1f);
    this->isCharging = false;

    if (player->stateFlags2 & PLAYER_STATE2_20000) {
        if (!gSaveContext.save.saveInfo.playerData.isMagicAcquired || (gSaveContext.magicState != MAGIC_STATE_IDLE) ||
            ((ENMTHUNDER_GET_MAGIC_COST(&this->actor) != 0) &&
             !Magic_Consume(play, ENMTHUNDER_GET_MAGIC_COST(&this->actor), MAGIC_CONSUME_NOW))) {
            AudioSfx_PlaySfx(NA_SE_IT_ROLLING_CUT, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                             &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
            AudioSfx_PlaySfx(NA_SE_IT_SWORD_SWING_HARD, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                             &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
            Actor_Kill(&this->actor);
            return;
        }

        player->stateFlags2 &= ~PLAYER_STATE2_20000;
        this->isCharging = false;

        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_GREAT_SPIN_ATTACK)) {
            player->unk_B08 = 1.0f;
            this->collider.elem.atDmgInfo.damage = sDamages[this->type + ENMTHUNDER_TYPE_MAX];
            this->subtype = ENMTHUNDER_SUBTYPE_SPIN_GREAT;
            if (this->type == ENMTHUNDER_TYPE_GREAT_FAIRYS_SWORD) {
                this->scaleTarget = 6;
            } else if (this->type == ENMTHUNDER_TYPE_GILDED_SWORD) {
                this->scaleTarget = 4;
            } else {
                this->scaleTarget = 3;
            }
        } else {
            player->unk_B08 = 0.5f;
            this->collider.elem.atDmgInfo.damage = sDamages[this->type];
            this->subtype = ENMTHUNDER_SUBTYPE_SPIN_REGULAR;
            if (this->type == ENMTHUNDER_TYPE_GREAT_FAIRYS_SWORD) {
                this->scaleTarget = 4;
            } else if (this->type == ENMTHUNDER_TYPE_GILDED_SWORD) {
                this->scaleTarget = 3;
            } else {
                this->scaleTarget = 2;
            }
        }

        if (player->meleeWeaponAnimation < PLAYER_MWA_SPIN_ATTACK_1H) {
            this->subtype += ENMTHUNDER_SUBTYPE_SWORDBEAM_GREAT;
            this->actionFunc = EnMThunder_SwordBeam_Attack;
            this->timer = 1;
            this->scaleTarget = 12;
            this->collider.elem.atDmgInfo.dmgFlags = DMG_SWORD_BEAM;
            this->collider.elem.atDmgInfo.damage = 3;
        } else {
            this->actionFunc = EnMThunder_Spin_Attack;
            this->timer = 8;
        }

        AudioSfx_PlaySfx(NA_SE_IT_ROLLING_CUT_LV1, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                         &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);

        this->lightColorFrac = 1.0f;
    } else {
        this->actionFunc = EnMThunder_Charge;
    }

    this->actor.child = NULL;
}
