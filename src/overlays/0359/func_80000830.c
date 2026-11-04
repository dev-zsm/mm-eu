// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_CrashingMoon_HandleGiantsCutscene(EnFall* this, PlayState* play) {
    static s32 sGiantsCutsceneState = 0;

    if ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 1) && (play->csCtx.scriptIndex == 0)) {
        switch (sGiantsCutsceneState) {
            case 0:
                if (play->csCtx.state != CS_STATE_IDLE) {
                    sGiantsCutsceneState += 2;
                }
                break;

            case 2:
                if (CHECK_QUEST_ITEM(QUEST_REMAINS_ODOLWA) && CHECK_QUEST_ITEM(QUEST_REMAINS_GOHT) &&
                    CHECK_QUEST_ITEM(QUEST_REMAINS_GYORG) && CHECK_QUEST_ITEM(QUEST_REMAINS_TWINMOLD)) {
                    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_93_04)) {
                        if (CutsceneManager_IsNext(12)) {
                            CutsceneManager_Start(12, &this->actor);
                            sGiantsCutsceneState++;
                        } else {
                            CutsceneManager_Queue(12);
                        }
                    } else if (CutsceneManager_IsNext(11)) {
                        CutsceneManager_Start(11, &this->actor);
                        SET_WEEKEVENTREG(WEEKEVENTREG_93_04);
                        sGiantsCutsceneState++;
                    } else {
                        CutsceneManager_Queue(11);
                    }
                } else if (play->csCtx.curFrame > 1600) {
                    play->nextEntrance = ENTRANCE(CLOCK_TOWER_ROOFTOP, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF2;
                    play->transitionTrigger = TRANS_TRIGGER_START;
                    play->transitionType = TRANS_TYPE_FADE_BLACK;
                    gSaveContext.nextTransitionType = TRANS_TYPE_FADE_BLACK;
                    sGiantsCutsceneState = 9;
                }
                break;

            case 9:
                play->csCtx.curFrame--;
                break;

            default:
                break;
        }
    }
}
