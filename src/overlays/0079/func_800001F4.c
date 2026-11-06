// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_viewer.h"

void ref_func_8089F014(EnViewer* this, PlayState* play, f32 arg2) {
    if (arg2 > 1.0f) {
        arg2 = 1.0f;
    } else if (arg2 < 0.0f) {
        arg2 = 0.0f;
    }

    play->envCtx.lightSettingOverride = 0;
    play->envCtx.lightBlendOverride = LIGHT_BLEND_OVERRIDE_FULL_CONTROL;
    play->envCtx.lightSetting = this->actor.world.rot.x;
    play->envCtx.prevLightSetting = this->actor.world.rot.z;
    play->envCtx.lightBlend = arg2;
}
