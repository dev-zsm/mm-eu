// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_moonend.h"

void ref_func_80C17C48(DemoMoonend* this, PlayState* play) {
    if (Keyframe_UpdateFlex(&this->kfSkelAnime)) {
        this->actor.home.rot.z = 0;
    }
    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        u16 cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;

        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));

        if (this->cueId != cueId) {
            this->cueId = cueId;
            switch (this->cueId) {
                case 1:
                    this->actor.draw = DemoMoonend_Draw;
                    Keyframe_FlexPlayOnce(&this->kfSkelAnime, &object_moonened_KFAnim_001214);
                    this->kfSkelAnime.frameCtrl.speed = 0.0f;
                    break;

                case 2:
                    this->actor.draw = DemoMoonend_Draw;
                    Keyframe_FlexPlayOnce(&this->kfSkelAnime, &object_moonened_KFAnim_001214);
                    this->kfSkelAnime.frameCtrl.speed = 2.0f / 3.0f;
                    Actor_PlaySfx(&this->actor, NA_SE_EV_MOON_EXPLOSION);
                    this->actor.home.rot.z = 1;
                    break;

                default:
                    break;
            }
        }
        if (this->actor.home.rot.z != 0) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_EARTHQUAKE_LAST2 - SFX_FLAG);
        }
    } else {
        this->actor.draw = NULL;
    }
    if ((play->csCtx.state != CS_STATE_IDLE) && (gSaveContext.sceneLayer == 8) && (play->csCtx.scriptIndex == 0)) {
        switch (play->csCtx.curFrame) {
            case 5:
                Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM1);
                break;

            case 50:
                Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM2);
                break;

            case 100:
                Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM3);
                break;

            case 150:
                Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM2);
                break;

            case 200:
                Actor_PlaySfx(&this->actor, NA_SE_EN_MOON_SCREAM4);
                break;

            default:
                break;
        }
    }
}
