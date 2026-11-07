// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tag.h"

s32 ref_func_80C224D8(Actor* thisx, PlayState* play) {
    DmTag* this = (DmTag*)thisx;
    Actor* sp30;
    Actor* sp2C;
    s16 csId = this->actor.csId;
    s32 ret = false;

    sp30 = DmTag_FindActor(this, play, ACTORCAT_NPC, ACTOR_EN_AN);
    sp2C = DmTag_FindActor(this, play, ACTORCAT_NPC, ACTOR_EN_AH);

    switch (this->unk_1A4) {
        case 0:
            if (ref_func_80C22400(this, csId)) {
                if ((sp2C != NULL) && (sp2C->update != NULL)) {
                    Camera_SetTargetActor(Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(csId)), sp2C);
                }
                this->unk_1A4++;
                ret = true;
            }
            break;

        case 1:
            if ((sp30 != NULL) && (sp30->update != NULL)) {
                Camera_SetTargetActor(Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(ref_func_80C2247C(this, 0))),
                                      sp30);
            }
            this->unk_1A4++;
            ret = true;
            break;

        case 2:
            CutsceneManager_Stop(ref_func_80C2247C(this, 0));
            if (ref_func_80C22400(this, ref_func_80C2247C(this, 1))) {
                this->unk_1A4++;
                ret = true;
            }
            break;

        case 3:
            CutsceneManager_Stop(ref_func_80C2247C(this, 1));
            if (ref_func_80C22400(this, ref_func_80C2247C(this, 2))) {
                this->unk_1A4++;
                ret = true;
            }
            break;

        case 4:
            CutsceneManager_Stop(ref_func_80C2247C(this, 2));
            if (ref_func_80C22400(this, ref_func_80C2247C(this, 3))) {
                this->unk_1A4++;
                ret = true;
            }
            break;

        case 5:
            CutsceneManager_Stop(ref_func_80C2247C(this, 3));
            if (ref_func_80C22400(this, ref_func_80C2247C(this, 4))) {
                this->unk_1A4++;
                ret = true;
            }
            break;

        case 6:
            Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_WAIT);
            play->nextEntrance = ENTRANCE(STOCK_POT_INN, 5);
            gSaveContext.nextCutsceneIndex = 0;
            play->transitionTrigger = TRANS_TRIGGER_START;
            play->transitionType = TRANS_TYPE_FADE_BLACK;
            gSaveContext.nextTransitionType = TRANS_TYPE_FADE_BLACK_SLOW;
            this->unk_1A4++;
            break;

        default:
            break;
    }
    return ret;
}
