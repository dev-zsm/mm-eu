// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_EnableUnderwaterLights(PlayState* play, s32 waterLightsIndex) {
    if (waterLightsIndex == WATERBOX_LIGHT_INDEX_NONE) {
        waterLightsIndex = 0;
    }

    if (play->envCtx.lightMode == LIGHT_MODE_TIME) {
        if (!ref_D_801F4F31) {
            ref_D_801F4F31 = true;
            gLightConfigAfterUnderwater = play->envCtx.changeLightNextConfig;
            if (play->envCtx.lightConfig != waterLightsIndex) {
                play->envCtx.lightConfig = waterLightsIndex;
                play->envCtx.changeLightNextConfig = waterLightsIndex;
            }
        } else if ((play->envCtx.lightConfig != waterLightsIndex) && (play->envCtx.changeLightTimer == 0)) {
            play->envCtx.changeLightEnabled = true;
            play->envCtx.changeLightNextConfig = waterLightsIndex;
            play->envCtx.changeDuration = 20;
            play->envCtx.changeLightTimer = play->envCtx.changeDuration;
        }
    } else if (play->envCtx.lightSettingOverride == LIGHT_SETTING_OVERRIDE_NONE) {
        if (!ref_D_801F4F31) {
            ref_D_801F4F31 = true;
            gLightConfigAfterUnderwater = play->envCtx.lightSetting;
        }
        play->envCtx.lightBlendEnabled = false; 
        play->envCtx.lightSettingOverride = waterLightsIndex;
    }
}
