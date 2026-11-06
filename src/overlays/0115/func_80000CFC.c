// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DCB7C(ObjectKankyo* this, PlayState* play) {
    if (play->envCtx.precipitation[PRECIP_SNOW_CUR] < play->envCtx.precipitation[PRECIP_SNOW_MAX]) {
        if ((play->state.frames % 16) == 0) {
            play->envCtx.precipitation[PRECIP_SNOW_CUR] += 2;
        }
    } else if (play->envCtx.precipitation[PRECIP_SNOW_MAX] < play->envCtx.precipitation[PRECIP_SNOW_CUR]) {
        if ((play->state.frames % 16) == 0) {
            play->envCtx.precipitation[PRECIP_SNOW_CUR] -= 2;
        }
    }
    ref_func_808DC454(this, play);
}
