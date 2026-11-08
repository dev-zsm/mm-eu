// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DCBF8(ObjectKankyo* this, PlayState* play) {
    f32 temp_f0;

    if ((play->envCtx.precipitation[PRECIP_SNOW_CUR] > 0) && (this->unk_114C == 0)) {
        if ((play->state.frames % 16) == 0) {
            play->envCtx.precipitation[PRECIP_SNOW_CUR] -= 9;
            if ((s8)play->envCtx.precipitation[PRECIP_SNOW_CUR] < 0) {
                play->envCtx.precipitation[PRECIP_SNOW_CUR] = 0;
            }
        }
    }

    temp_f0 = (f32)play->envCtx.precipitation[PRECIP_SNOW_CUR] / 128;
    temp_f0 = CLAMP(temp_f0, 0.0f, 1.0f);

    if (temp_f0 > 0.01f) {
        ref_D_801F4E30 = 155.0f * temp_f0;
        play->envCtx.sandstormState = SANDSTORM_A;
    } else {
        ref_D_801F4E30 = 0;
        play->envCtx.sandstormState = SANDSTORM_A;
    }
    ref_func_808DC454(this, play);
}
