// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808BA10C(DoorWarp1* this, PlayState* play) {
    s32 phi_v0_2;
    u8 phi_a0;
    s32 phi_v0_3;

    if ((play->sceneId == SCENE_MITURIN_BS) || (play->sceneId == SCENE_HAKUGIN_BS) ||
        (play->sceneId == SCENE_INISIE_BS) || (play->sceneId == SCENE_SEA_BS)) {
        gDungeonBossWarpSceneId = play->sceneId;
        if (play->sceneId == SCENE_MITURIN_BS) {
            phi_v0_2 = 0;
        } else if (play->sceneId == SCENE_HAKUGIN_BS) {
            phi_v0_2 = 1;
        } else if (play->sceneId == SCENE_INISIE_BS) {
            phi_v0_2 = 2;
        } else if (play->sceneId == SCENE_SEA_BS) {
            phi_v0_2 = 3;
        } else {
            phi_v0_2 = 0;
        }

        if (this->unk_202 != 0) {
            if (phi_v0_2 > 0) {
                SET_WEEKEVENTREG(WEEKEVENTREG_ENTERED_WOODFALL_TEMPLE_PRISON);
            }

            switch (phi_v0_2) {
                case 0:
                    phi_a0 = gSaveContext.save.saveInfo.unk_EA8[0] & 0xFF;
                    break;

                case 1:
                    phi_a0 = (gSaveContext.save.saveInfo.unk_EA8[0] & 0xFF00) >> 8;
                    break;

                case 2:
                    phi_a0 = (gSaveContext.save.saveInfo.unk_EA8[0] & 0xFF0000) >> 0x10;
                    break;

                case 3:
                    phi_a0 = (gSaveContext.save.saveInfo.unk_EA8[0] & 0xFF000000) >> 0x18;
                    break;

                default:
                    phi_a0 = 0;
                    break;
            }

            switch (phi_a0) {
                case 0:
                    phi_v0_3 = 10;
                    break;

                case 1:
                    phi_v0_3 = 0;
                    break;

                case 2:
                    phi_v0_3 = 1;
                    break;

                case 3:
                    phi_v0_3 = 2;
                    break;

                default:
                    phi_v0_3 = 10;
                    break;
            }

            play->nextEntrance = ENTRANCE(GIANTS_CHAMBER, 0);
            if (phi_v0_3 < 10) {
                gSaveContext.nextCutsceneIndex = phi_v0_3 + 0xFFF0;
            }

            play->transitionTrigger = TRANS_TRIGGER_START;
            play->transitionType = TRANS_TYPE_FADE_WHITE;
            gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
        } else {
            switch (phi_v0_2) {
                case 0:
                    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) {
                        
                        SET_WEEKEVENTREG(WEEKEVENTREG_ENTERED_WOODFALL_TEMPLE_PRISON);
                        play->nextEntrance = ENTRANCE(WOODFALL_TEMPLE, 1);
                        play->transitionTrigger = TRANS_TRIGGER_START;
                        play->transitionType = TRANS_TYPE_FADE_WHITE;
                        gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
                    } else {
                        play->nextEntrance = ENTRANCE(WOODFALL, 0);
                        gSaveContext.nextCutsceneIndex = 0xFFF0;
                        play->transitionTrigger = TRANS_TRIGGER_START;
                        play->transitionType = TRANS_TYPE_FADE_WHITE;
                        gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
                    }
                    break;

                case 1:
                    SET_WEEKEVENTREG(WEEKEVENTREG_CLEARED_SNOWHEAD_TEMPLE);
                    play->nextEntrance = ENTRANCE(MOUNTAIN_VILLAGE_SPRING, 7);
                    play->transitionTrigger = TRANS_TRIGGER_START;
                    play->transitionType = TRANS_TYPE_FADE_WHITE;
                    gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
                    break;

                case 3:
                    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_GREAT_BAY_TEMPLE)) {
                        play->nextEntrance = ENTRANCE(ZORA_CAPE, 9);
                        gSaveContext.nextCutsceneIndex = 0xFFF0;
                        play->transitionTrigger = TRANS_TRIGGER_START;
                        play->transitionType = TRANS_TYPE_FADE_WHITE;
                        gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
                    } else {
                        SET_WEEKEVENTREG(WEEKEVENTREG_CLEARED_GREAT_BAY_TEMPLE);
                        play->nextEntrance = ENTRANCE(ZORA_CAPE, 8);
                        gSaveContext.nextCutsceneIndex = 0xFFF0;
                        play->transitionTrigger = TRANS_TRIGGER_START;
                        play->transitionType = TRANS_TYPE_FADE_WHITE;
                        gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
                    }
                    break;

                case 2:
                    SET_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE);
                    play->nextEntrance = ENTRANCE(IKANA_CANYON, 15);
                    gSaveContext.nextCutsceneIndex = 0xFFF2;
                    play->transitionTrigger = TRANS_TRIGGER_START;
                    play->transitionType = TRANS_TYPE_FADE_WHITE;
                    gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
                    break;
            }
        }
    } else if (DOORWARP1_GET_FF00_1(&this->dyna.actor) != 0xFF) {
        if (DOORWARP1_GET_FF(&this->dyna.actor) == ENDOORWARP1_FF_6) {
            gSaveContext.respawnFlag = -2;
        }
        play->nextEntrance = play->setupExitList[DOORWARP1_GET_FF00_3(&this->dyna.actor)];
        Scene_SetExitFade(play);
        play->transitionTrigger = TRANS_TRIGGER_START;
    } else {
        ref_func_80169FDC(play);
    }
}
