// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966BF4(EnWeatherTag* this, PlayState* play) {
    u8 changeLightNextConfig;
    CsCmdActorCue* cue;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_567)) {
        cue = play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_567)];
        if ((play->csCtx.curFrame >= cue->startFrame) && (cue->id >= 2)) {
            switch (gSaveContext.save.day) {
                case 0:
                case 1:
                default:
                    changeLightNextConfig = 0;
                    break;

                case 2:
                    changeLightNextConfig = 3;
                    break;

                case 3:
                    changeLightNextConfig = 4;
                    break;
            }

            Math_SmoothStepToF(&ref_D_801F4E74, 0.0f, 0.2f, 0.02f, 0.001f);

            if (play->envCtx.changeLightNextConfig != changeLightNextConfig) {
                play->envCtx.changeLightEnabled = true;
                play->envCtx.changeLightNextConfig = changeLightNextConfig;
                play->envCtx.changeDuration = 100;
                play->envCtx.changeLightTimer = play->envCtx.changeDuration;
            }
        }
    }
}
