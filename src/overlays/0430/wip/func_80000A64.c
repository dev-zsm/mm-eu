// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTsn_Object_Talk), score 9.00 (9 differ, size +3)
#include "generated/mm/z_en_tsn.h"

void func_80000A64(EnTsn* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 pad[2];

    if ((this->flags & ENTSN_OFFERING_ITEM) && (play->msgCtx.currentTextId == 0x1078)) {
        this->flags &= ~ENTSN_OFFERING_ITEM;
        Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanTwoHandTalkAnim, -10.0f);
    }

    switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_CLOSING:
            break;

        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(play)) {
                switch (play->msgCtx.currentTextId) {
                    case 0x106E:
                        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMANS_SEAHORSE)) {
                            Message_ContinueTextbox(play, 0x1074);
                        } else {
                            Message_ContinueTextbox(play, 0x106F);
                        }
                        this->flags |= ENTSN_PLAYER_LOOKS_AT_FISHERMAN;
                        SET_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMANS_SEAHORSE);
                        ENTSN_SET_Z(&this->fisherman->actor, true);
                        this->flags |= ENTSN_CS_QUEUED;
                        break;

                    case 0x106F:
                    case 0x1070:
                    case 0x1071:
                    case 0x1072:
                        Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                        break;

                    case 0x1076:
                    case 0x1079:
                        Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanOneHandTalkAnim, -10.0f);
                        Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                        break;

                    case 0x107A:
                        Message_ContinueTextbox(play, 0x10A6);
                        break;

                    case 0x1075:
                    case 0x1078:
                        player->exchangeItemAction = PLAYER_IA_NONE;
                        Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                        Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanIdleAnim, -10.0f);
                        break;

                    case 0x107C:
                        if (Inventory_HasEmptyBottle()) {
                            SET_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_SEAHORSE);
                            Message_CloseTextbox(play);
                            this->actionFunc = EnTsn_GiveSeahorse;
                            EnTsn_GiveSeahorse(this, play);
                            this->flags &= ~ENTSN_PLAYER_LOOKS_AT_FISHERMAN;
                            this->actor.focus.pos = this->actor.world.pos;
                            CutsceneManager_Stop(this->actor.csId);
                            this->actor.flags &= ~ACTOR_FLAG_TALK;
                            REMOVE_QUEST_ITEM(QUEST_PICTOGRAPH);
                        } else {
                            Message_ContinueTextbox(play, 0x10A8);
                        }
                        break;

                    case 0x1073:
                    case 0x1074:
                        Message_ContinueTextbox(play, 0xFF);
                        this->actionFunc = EnTsn_Object_ItemExchange;
                        break;

                    case 0x107B:
                        player->exchangeItemAction = PLAYER_IA_NONE;
                        Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                        Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanIdleAnim, -10.0f);
                        break;

                    case 0x1077:
                    case 0x10A6:
                    case 0x10A8:
                        Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanIdleAnim, -10.0f);
                        EnTsn_Object_EndTalk(this, play);
                        this->actor.flags &= ~ACTOR_FLAG_TALK;
                        this->actionFunc = EnTsn_Object_WaitForTextboxClose;
                        break;

                    case 0x108A:
                    case 0x1091:
                        SET_WEEKEVENTREG(WEEKEVENTREG_LOOKED_AT_PIRATE_POSTER);
                        Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                        this->flags |= ENTSN_PLAYER_LOOKS_AT_FISHERMAN;
                        this->actor.textId = 0x1091;
                        break;

                    case 0x108B:
                    case 0x108C:
                    case 0x108D:
                    case 0x108E:
                    case 0x108F:
                        Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                        break;

                    case 0x1092:
                        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_SEAHORSE)) {
                            EnTsn_Object_EndTalk(this, play);
                        } else {
                            Message_ContinueTextbox(play, 0x10A7);
                            Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanOneHandTalkAnim, -10.0f);
                        }
                        break;

                    case 0x10A7:
                        Animation_MorphToLoop(&this->fisherman->skelAnime, &gFishermanIdleAnim, -10.0f);
                        EnTsn_Object_EndTalk(this, play);
                        break;

                    case 0x1090:
                        EnTsn_Object_EndTalk(this, play);
                        break;

                    case 0x10A9:
                        EnTsn_Object_EndTalk(this, play);
                        this->actor.flags &= ~ACTOR_FLAG_TALK;
                        this->actionFunc = EnTsn_Object_WaitForTextboxClose;
                        break;

                    default:
                        break;
                }
            }
            break;

        default:
            break;
    }

    if (this->flags & ENTSN_PLAYER_LOOKS_AT_FISHERMAN) {
        if (this->fisherman != NULL) {
            Math_SmoothStepToF(&this->actor.focus.pos.x, this->fisherman->actor.focus.pos.x, 0.8f, 100.0f, 5.0f);
            Math_SmoothStepToF(&this->actor.focus.pos.y, this->fisherman->actor.focus.pos.y, 0.8f, 100.0f, 5.0f);
            Math_SmoothStepToF(&this->actor.focus.pos.z, this->fisherman->actor.focus.pos.z, 0.8f, 100.0f, 5.0f);
        }
    }

    if (this->flags & ENTSN_CS_QUEUED) {
        if (this->actor.csId == CS_ID_NONE) {
            this->flags &= ~ENTSN_CS_QUEUED;
        } else if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            CutsceneManager_Queue(this->actor.csId);
        } else if (CutsceneManager_IsNext(this->actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
            this->flags &= ~ENTSN_CS_QUEUED;
        } else {
            CutsceneManager_Queue(this->actor.csId);
        }
    }
}
