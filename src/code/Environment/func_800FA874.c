// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_ChangeLightSetting(PlayState* play, u8 lightSetting) {
    if (play->envCtx.lightMode == LIGHT_MODE_TIME) {
        if ((lightSetting == LIGHT_SETTING_MAX) || ref_D_801F4F33) {
            if (ref_D_801F4F30 != 0xFF) {
                play->envCtx.changeLightEnabled = true;
                play->envCtx.changeLightNextConfig = ref_D_801F4F30;
                play->envCtx.changeDuration = 20;
                play->envCtx.changeLightTimer = play->envCtx.changeDuration;
                ref_D_801F4F30 = 0xFF;
            }
        } else if (play->envCtx.changeLightNextConfig != lightSetting) {
            ref_D_801F4F30 = play->envCtx.lightConfig;
            play->envCtx.changeLightEnabled = true;
            play->envCtx.changeLightNextConfig = lightSetting;
            play->envCtx.changeDuration = 20;
            play->envCtx.changeLightTimer = play->envCtx.changeDuration;
        }
    } else if ((play->envCtx.lightSetting != lightSetting) && (play->envCtx.lightBlend >= 1.0f) &&
               (play->envCtx.lightSettingOverride == LIGHT_SETTING_OVERRIDE_NONE)) {
        if (lightSetting >= LIGHT_SETTING_MAX) {
            lightSetting = 0;
        }

        play->envCtx.lightBlend = 0.0f;
        play->envCtx.prevLightSetting = play->envCtx.lightSetting;
        play->envCtx.lightSetting = lightSetting;
    }
}
