// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_viewer.h"

void ref_func_8089F0A0(EnViewer* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    ref_D_8089F3E4++;
    if ((ref_D_8089F3E4 == ref_D_8089F3E0) && (play->envCtx.lightSettingOverride != LIGHT_SETTING_OVERRIDE_NONE)) {
        play->envCtx.lightSettingOverride = LIGHT_SETTING_OVERRIDE_NONE;
        play->envCtx.lightBlendOverride = LIGHT_BLEND_OVERRIDE_NONE;
        play->envCtx.lightBlend = 1.0f;
        Environment_ChangeLightSetting(
            play, SurfaceType_GetLightSettingIndex(&play->colCtx, player->actor.floorPoly, player->actor.floorBgId));
        play->envCtx.lightBlend = 1.0f;
        play->envCtx.prevLightSetting = play->envCtx.lightSetting;
    }
}
