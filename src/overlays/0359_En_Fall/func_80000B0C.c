// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_StoppedOpenMouthMoon_PerformCutsceneActions(EnFall* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133)) {
        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133)]->id) {
            case 3:
                if (this->eyeGlowIntensity == 0.0f) {
                    Actor_PlaySfx(&this->actor, NA_SE_EV_MOON_EYE_FLASH);
                }
                this->eyeGlowIntensity += 1 / 30.0f;
                if (this->eyeGlowIntensity > 1.0f) {
                    this->eyeGlowIntensity = 1.0f;
                }
                break;

            case 4:
                this->actor.draw = EnFall_OpenMouthMoon_Draw;
                break;

            default:
                break;
        }
    }
}
