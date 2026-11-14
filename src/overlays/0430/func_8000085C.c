// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tsn.h"

void func_8000085C(EnTsn* this, PlayState* play) {
    PlayerItemAction itemAction;
    Player* player = GET_PLAYER(play);

    if (Message_GetState(&play->msgCtx) == TEXT_STATE_PAUSE_MENU) {
        itemAction = ref_func_80123810(play);

        if (itemAction != PLAYER_IA_NONE) {
            SET_WEEKEVENTREG(WEEKEVENTREG_26_02);
        }

        if (itemAction > PLAYER_IA_NONE) {
            Message_CloseTextbox(play);
            this->actionFunc = EnTsn_Object_Talk;
            if (itemAction == PLAYER_IA_PICTOGRAPH_BOX) {
                if (CHECK_QUEST_ITEM(QUEST_PICTOGRAPH)) {
                    if (Snap_CheckFlag(PICTO_VALID_PIRATE_GOOD)) {
                        player->actor.textId = 0x107B;
                    } else if (Snap_CheckFlag(PICTO_VALID_PIRATE_TOO_FAR)) {
                        player->actor.textId = 0x10A9;
                    } else {
                        player->actor.textId = 0x1078;
                        this->flags |= ENTSN_OFFERING_ITEM;
                    }
                } else {
                    player->actor.textId = 0x1078;
                    this->flags |= ENTSN_OFFERING_ITEM;
                }
            } else if (itemAction == PLAYER_IA_HOOKSHOT) {
                player->actor.textId = 0x1075;
            } else {
                player->actor.textId = 0x1078;
                this->flags |= ENTSN_OFFERING_ITEM;
            }
        } else if (itemAction <= PLAYER_IA_MINUS1) {
            Message_ContinueTextbox(play, 0x1078);
            Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanTwoHandTalkAnim, -10.0f);
            this->actionFunc = EnTsn_Object_Talk;
        }
    }
}
