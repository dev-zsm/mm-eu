// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTsn_Fisherman_Talk), score 6.00 (6 differ, size +3)
#include "generated/mm/z_en_tsn.h"

void func_80000370(EnTsn* this, PlayState* play) {
    switch (play->msgCtx.currentTextId) {
        case 0x107F:
        case 0x1080:
        case 0x1081:
        case 0x1082:
        case 0x1083:
        case 0x1084:
        case 0x1085:
        case 0x1086:
        case 0x1087:
        case 0x1088:
        case 0x1089:
        case 0x1093:
            Math_SmoothStepToS(&this->actor.world.rot.y, this->actor.yawTowardsPlayer, 6, 0x1838, 0x64);
            this->actor.shape.rot.y = this->actor.world.rot.y;
            break;
    }

    if ((Message_GetState(&play->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
        switch (play->msgCtx.currentTextId) {
            case 0x107F:
            case 0x1081:
                Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                break;

            case 0x1080:
                Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                Animation_MorphToLoop(&this->skelAnime, &gFishermanTwoHandTalkAnim, -10.0f);
                break;

            case 0x1082:
                Animation_MorphToLoop(&this->skelAnime, &gFishermanIdleAnim, -10.0f);
                SET_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMAN_AS_ZORA);
                Message_CloseTextbox(play);
                this->actionFunc = EnTsn_Fisherman_Idle;
                this->actor.textId = 0;
                break;

            case 0x1083:
                SET_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMAN_AS_ZORA);
                Message_CloseTextbox(play);
                this->actionFunc = EnTsn_Fisherman_Idle;
                this->actor.textId = 0;
                break;

            case 0x1084:
                Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                Animation_MorphToLoop(&this->skelAnime, &gFishermanOneHandTalkAnim, -10.0f);
                break;

            case 0x1085:
            case 0x1086:
                Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                break;

            case 0x1089:
            case 0x1093:
                SET_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMAN_AS_HUMAN);
                Message_CloseTextbox(play);
                Animation_MorphToLoop(&this->skelAnime, &gFishermanIdleAnim, -10.0f);
                this->actionFunc = EnTsn_Fisherman_Idle;
                this->actor.textId = 0;
                break;

            case 0x1087:
                Animation_MorphToLoop(&this->skelAnime, &gFishermanTwoHandTalkAnim, -10.0f);
                Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                break;

            case 0x1088:
                SET_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMAN_AS_HUMAN);
                if (INV_CONTENT(ITEM_MASK_ZORA) == ITEM_MASK_ZORA) {
                    Message_CloseTextbox(play);
                    Animation_MorphToLoop(&this->skelAnime, &gFishermanIdleAnim, -10.0f);
                    this->actionFunc = EnTsn_Fisherman_Idle;
                    this->actor.textId = 0;
                } else {
                    Message_ContinueTextbox(play, 0x1093);
                    Animation_MorphToLoop(&this->skelAnime, &gFishermanIdleAnim, -10.0f);
                }
                break;

            case 0x107E:
                Message_CloseTextbox(play);
                this->actionFunc = EnTsn_Fisherman_Idle;
                this->actor.textId = 0;
                break;
        }
    }
}
