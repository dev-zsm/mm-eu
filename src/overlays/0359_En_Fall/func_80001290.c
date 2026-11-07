// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Fireball_Update(Actor* thisx, PlayState* play) {
    EnFall* this = (EnFall*)thisx;

    if ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 0) && (play->csCtx.scriptIndex == 2)) {
        play->skyboxCtx.rot.y -= 0.05f;
    }

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_450)) {
        this->actor.draw = EnFall_Fireball_Draw;
        if (this->flags & FLAG_FIRE_BALL_INTENSIFIES) {
            this->fireballIntensity += 0.01f;
            if (this->fireballIntensity > 1.0f) {
                this->fireballIntensity = 1.0f;
            }
        }
        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, 450));

        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, 450)]->id) {
            default:
                this->actor.draw = NULL;
                this->fireballAlpha = 0;
                break;

            case 2:
                if (this->fireballAlpha < 100) {
                    this->fireballAlpha += 4;
                }
                if (this->fireballAlpha > 100) {
                    this->fireballAlpha = 100;
                }
                EnFall_Fireball_SetPerVertexAlpha(this->fireballAlpha * 0.01f);
                break;

            case 3:
                if (this->fireballAlpha > 0) {
                    this->fireballAlpha -= 2;
                }
                if (this->fireballAlpha < 0) {
                    this->fireballAlpha = 0;
                }
                EnFall_Fireball_SetPerVertexAlpha(this->fireballAlpha * 0.01f);
                break;

            case 4:
                this->flags |= FLAG_FIRE_BALL_INTENSIFIES;
                break;

            case 5:
                break;
        }
    } else {
        this->actor.draw = NULL;
    }

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_450) && (this->fireballAlpha > 0)) {
        Audio_PlaySfx_2(NA_SE_EV_MOON_FALL_LAST - SFX_FLAG);
    }
    Actor_SetScale(&this->actor, this->scale * 1.74f);
}
