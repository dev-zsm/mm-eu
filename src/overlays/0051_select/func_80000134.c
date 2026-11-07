// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_select.h"

void MapSelect_UpdateMenu(MapSelectState* this) {
    s32 playerForm;
    Input* controller1 = CONTROLLER1(&this->state);
    s32 stickY;
    s32 pad[2];
    s16 i;
    s32 updateRate;

    if (this->verticalInputAccumulator == 0) {
        if (CHECK_BTN_ALL(controller1->press.button, BTN_A) || CHECK_BTN_ALL(controller1->press.button, BTN_START)) {
            for (i = 0; i < TIMER_ID_MAX; i++) {
                gSaveContext.timerStates[i] = TIMER_STATE_OFF;
                gSaveContext.timerCurTimes[i] = SECONDS_TO_TIMER(0);
                gSaveContext.timerTimeLimits[i] = SECONDS_TO_TIMER(0);
                gSaveContext.timerStartOsTimes[i] = 0;
                gSaveContext.timerStopTimes[i] = SECONDS_TO_TIMER(0);
                gSaveContext.timerPausedOsTimes[i] = 0;
            }
            gSaveContext.minigameStatus = MINIGAME_STATUS_INACTIVE;

            if (this->scenes[this->currentScene].loadFunc != NULL) {
                this->scenes[this->currentScene].loadFunc(this, this->scenes[this->currentScene].entrance, this->opt);
            }
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_B)) {
            playerForm = GET_PLAYER_FORM - 1;
            if (playerForm < PLAYER_FORM_FIERCE_DEITY) {
                playerForm = PLAYER_FORM_HUMAN;
            }
            gSaveContext.save.playerForm = playerForm;
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_Z)) {
            if (gSaveContext.save.cutsceneIndex == 0x8000) {
                gSaveContext.save.cutsceneIndex = 0;
            } else if (gSaveContext.save.cutsceneIndex == 0) {
                gSaveContext.save.cutsceneIndex = 0x8800;
            } else if (gSaveContext.save.cutsceneIndex == 0x8800) {
                gSaveContext.save.cutsceneIndex = 0xFFF0;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF0) {
                gSaveContext.save.cutsceneIndex = 0xFFF1;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF1) {
                gSaveContext.save.cutsceneIndex = 0xFFF2;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF2) {
                gSaveContext.save.cutsceneIndex = 0xFFF3;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF3) {
                gSaveContext.save.cutsceneIndex = 0xFFF4;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF4) {
                gSaveContext.save.cutsceneIndex = 0xFFF5;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF5) {
                gSaveContext.save.cutsceneIndex = 0xFFF6;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF6) {
                gSaveContext.save.cutsceneIndex = 0xFFF7;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF7) {
                gSaveContext.save.cutsceneIndex = 0xFFF8;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF8) {
                gSaveContext.save.cutsceneIndex = 0xFFF9;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF9) {
                gSaveContext.save.cutsceneIndex = 0xFFFA;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFFA) {
                gSaveContext.save.cutsceneIndex = 0x8000;
            }
        } else if (CHECK_BTN_ALL(controller1->press.button, BTN_R)) {
            if (gSaveContext.save.cutsceneIndex == 0x8000) {
                gSaveContext.save.cutsceneIndex = 0xFFFA;
            } else if (gSaveContext.save.cutsceneIndex == 0) {
                gSaveContext.save.cutsceneIndex = 0x8000;
            } else if (gSaveContext.save.cutsceneIndex == 0x8800) {
                gSaveContext.save.cutsceneIndex = 0;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF0) {
                gSaveContext.save.cutsceneIndex = 0x8800;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF1) {
                gSaveContext.save.cutsceneIndex = 0xFFF0;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF2) {
                gSaveContext.save.cutsceneIndex = 0xFFF1;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF3) {
                gSaveContext.save.cutsceneIndex = 0xFFF2;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF4) {
                gSaveContext.save.cutsceneIndex = 0xFFF3;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF5) {
                gSaveContext.save.cutsceneIndex = 0xFFF4;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF6) {
                gSaveContext.save.cutsceneIndex = 0xFFF5;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF7) {
                gSaveContext.save.cutsceneIndex = 0xFFF6;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF8) {
                gSaveContext.save.cutsceneIndex = 0xFFF7;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFF9) {
                gSaveContext.save.cutsceneIndex = 0xFFF8;
            } else if (gSaveContext.save.cutsceneIndex == 0xFFFA) {
                gSaveContext.save.cutsceneIndex = 0xFFF9;
            }
        }

        gSaveContext.save.isNight = false;
        if (gSaveContext.save.cutsceneIndex == 0x8800) {
            gSaveContext.save.isNight = true;
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_CUP)) {
            this->opt--;
        }
        if (CHECK_BTN_ALL(controller1->press.button, BTN_CDOWN)) {
            this->opt++;
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_CLEFT)) {
            if (gSaveContext.save.day > 1) {
                gSaveContext.save.day--;
            }
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_CRIGHT)) {
            if (gSaveContext.save.day < 4) {
                gSaveContext.save.day++;
            }
        }

        updateRate = R_UPDATE_RATE;
        stickY = controller1->rel.stick_y;
        if (stickY != 0) {
            this->verticalInput = (updateRate * stickY) / 7;
        } else {
            if (CHECK_BTN_ALL(controller1->press.button, BTN_DUP)) {
                if (this->lockUp == true) {
                    this->timerUp = 0;
                }
                if (this->timerUp == 0) {
                    this->timerUp = 20;
                    this->lockUp = true;

                    Audio_PlaySfx(NA_SE_IT_SWORD_IMPACT);
                    this->verticalInput = updateRate;
                }
            }

            if (CHECK_BTN_ALL(controller1->cur.button, BTN_DUP) && (this->timerUp == 0)) {
                Audio_PlaySfx(NA_SE_IT_SWORD_IMPACT);
                this->verticalInput = updateRate * 3;
            }

            if (CHECK_BTN_ALL(controller1->press.button, BTN_DDOWN)) {
                if (this->lockDown == true) {
                    this->timerDown = 0;
                }
                if (this->timerDown == 0) {
                    this->timerDown = 20;
                    this->lockDown = true;
                    Audio_PlaySfx(NA_SE_IT_SWORD_IMPACT);
                    this->verticalInput = -updateRate;
                }
            }
            if (CHECK_BTN_ALL(controller1->cur.button, BTN_DDOWN) && (this->timerDown == 0)) {
                Audio_PlaySfx(NA_SE_IT_SWORD_IMPACT);
                this->verticalInput = -updateRate * 3;
            }

            if (CHECK_BTN_ALL(controller1->press.button, BTN_DLEFT) ||
                CHECK_BTN_ALL(controller1->cur.button, BTN_DLEFT)) {
                Audio_PlaySfx(NA_SE_IT_SWORD_IMPACT);
                this->verticalInput = updateRate;
            }

            if (CHECK_BTN_ALL(controller1->press.button, BTN_DRIGHT) ||
                CHECK_BTN_ALL(controller1->cur.button, BTN_DRIGHT)) {
                Audio_PlaySfx(NA_SE_IT_SWORD_IMPACT);
                this->verticalInput = -updateRate;
            }
        }
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_L)) {
        this->pageDownIndex++;
        this->pageDownIndex =
            (this->pageDownIndex + ARRAY_COUNT(this->pageDownStops)) % ARRAY_COUNT(this->pageDownStops);
        this->currentScene = this->topDisplayedScene = this->pageDownStops[this->pageDownIndex];
    }

    this->verticalInputAccumulator += this->verticalInput;

    if (this->verticalInputAccumulator < -7) {
        this->verticalInput = 0;
        this->verticalInputAccumulator = 0;

        this->currentScene++;
        this->currentScene = (this->currentScene + this->count) % this->count;

        if (this->currentScene == ((this->topDisplayedScene + this->count + 19) % this->count)) {
            this->topDisplayedScene++;
            this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;
        }
    }

    if (this->verticalInputAccumulator > 7) {
        this->verticalInput = 0;
        this->verticalInputAccumulator = 0;

        if (this->currentScene == this->topDisplayedScene) {
            this->topDisplayedScene -= 2;
            this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;
        }

        this->currentScene--;
        this->currentScene = (this->currentScene + this->count) % this->count;

        if (this->currentScene == ((this->topDisplayedScene + this->count) % this->count)) {
            this->topDisplayedScene--;
            this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;
        }
    }

    this->currentScene = (this->currentScene + this->count) % this->count;
    this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;

    dREG(80) = this->currentScene;
    dREG(81) = this->topDisplayedScene;
    dREG(82) = this->pageDownIndex;

    if (this->timerUp != 0) {
        this->timerUp--;
    }

    if (this->timerUp == 0) {
        this->lockUp = false;
    }

    if (this->timerDown != 0) {
        this->timerDown--;
    }

    if (this->timerDown == 0) {
        this->lockDown = false;
    }
}
