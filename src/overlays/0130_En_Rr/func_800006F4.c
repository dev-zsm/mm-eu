// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA4F4(EnRr* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    u32 sp38;
    s32 sp34;
    f32 sp30;
    f32 sp2C;

    if (player->stateFlags2 & PLAYER_STATE2_80) {
        player->actor.parent = NULL;
        player->av2.actionVar2 = 100;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        this->unk_1F0 = 110;
        this->unk_1F6 = 2500;
        this->unk_210 = 0.0f;
        this->unk_20C = 0x800;

        if (((this->unk_1E2 == 0) && (GET_PLAYER_FORM == PLAYER_FORM_HUMAN)) &&
            (GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SHIELD) == EQUIP_VALUE_SHIELD_HERO)) {
            sp34 = true;
            this->unk_1E2 = Inventory_DeleteEquipment(play, EQUIP_VALUE_SHIELD_HERO);
        } else {
            sp34 = false;
        }

        if (sp34 && (Message_GetState(&play->msgCtx) == TEXT_STATE_NONE)) {
            Message_StartTextbox(play, 0xF6, NULL);
        }

        if (this->actor.params == LIKE_LIKE_PARAM_0) {
            sp38 = 8;
        } else {
            sp38 = 16;
        }

        sp30 = this->actor.scale.x * 210.52632f;
        sp2C = this->actor.scale.x * 631.579f;

        player->actor.world.pos.x += sp30 * Math_SinS(this->actor.shape.rot.y);
        player->actor.world.pos.y += sp2C;
        player->actor.world.pos.z += sp30 * Math_CosS(this->actor.shape.rot.y);

        ref_func_800B8D50(play, &this->actor, sp30, this->actor.shape.rot.y, sp2C, sp38);
        Actor_PlaySfx(&this->actor, NA_SE_EN_SUISEN_THROW);
    }
}
