// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_StoppedClosedMouthMoon_PerformCutsceneActions(EnFall* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133)) {
        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133)]->id) {
            case 2:
                Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133));
                break;

            case 4:
                this->actor.draw = NULL;
                break;

            default:
                break;
        }
    }

    if ((play->sceneId == SCENE_OKUJOU) && (gSaveContext.sceneLayer == 2)) {
        switch (play->csCtx.scriptIndex) {
            case 0:
                switch (play->csCtx.curFrame) {
                    case 1060:
                        Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM1);
                        break;

                    case 1089:
                        Actor_PlaySfx(&this->actor, NA_SE_EV_MOON_CRY);
                        break;

                    case 1303:
                        Actor_PlaySfx(&this->actor, NA_SE_EV_SLIP_MOON);
                        break;

                    default:
                        break;
                }
                if (play->csCtx.curFrame >= 1145) {
                    Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_FALL_POWER - SFX_FLAG);
                }
                break;

            case 1:
                switch (play->csCtx.curFrame) {
                    case 561:
                        Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM1);
                        break;

                    case 590:
                        Actor_PlaySfx(&this->actor, NA_SE_EV_MOON_CRY);
                        break;

                    case 737:
                        Actor_PlaySfx(&this->actor, NA_SE_EV_SLIP_MOON);
                        break;

                    default:
                        break;
                }
                if (play->csCtx.curFrame >= 650) {
                    Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_FALL_POWER - SFX_FLAG);
                }
                break;

            default:
                break;
        }
    }
}
