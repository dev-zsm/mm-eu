// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AAD4A8(DmChar05* this, PlayState* play) {
    if (DMCHAR05_GET(&this->actor) == DMCHAR05_0) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_109) &&
            (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_109)]->id == 3)) {
            if (Animation_OnFrame(&this->skelAnime, 14.0f) || Animation_OnFrame(&this->skelAnime, 15.0f)) {
                Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_0);
            } else if (Animation_OnFrame(&this->skelAnime, 19.0f)) {
                Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_1);
            }
        }
    } else if (DMCHAR05_GET(&this->actor) == DMCHAR05_1) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_473)) {
            if ((play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_473)]->id == 3) &&
                Animation_OnFrame(&this->skelAnime, 5.0f)) {
                Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_SAND);
            }
        }
    } else if (DMCHAR05_GET(&this->actor) == DMCHAR05_2) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_518) &&
            (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_518)]->id == 2)) {
            if (Animation_OnFrame(&this->skelAnime, 7.0f)) {
                Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_0);
            }

            if (Animation_OnFrame(&this->skelAnime, 14.0f)) {
                Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_1);
            }

            if (Animation_OnFrame(&this->skelAnime, 18.0f)) {
                Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_1);
            }
        }
    } else if (DMCHAR05_GET(&this->actor) == DMCHAR05_3) {
        if (play->sceneId == SCENE_OKUJOU) {
            if (gSaveContext.sceneLayer == 2) {
                if (play->csCtx.scriptIndex == 0) {
                    ref_func_80AAD3F8(this, play);
                } else if (play->csCtx.scriptIndex == 1) {
                    ref_func_80AAD450(this, play);
                }
            }
        } else if (play->sceneId == SCENE_SPOT00) {
            if (gSaveContext.sceneLayer == 9) {
                if ((play->csCtx.scriptIndex == 0) && (play->csCtx.curFrame == 255)) {
                    Actor_PlaySfx(&this->actor, NA_SE_EN_EVIL_POWER);
                }
            } else if ((gSaveContext.sceneLayer == 0xB) && (play->csCtx.curFrame == 115)) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_EVIL_POWER_PREDEMO);
            }
        }
    }
}
