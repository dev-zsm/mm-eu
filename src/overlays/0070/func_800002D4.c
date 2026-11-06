// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_arrow.h"

void ref_func_8088A514(EnArrow* this) {
    f32 temp_f0 = 16.0f - this->bubble.unk_144;

    Actor_SetSpeeds(&this->actor, CLAMP(temp_f0, 1.0f, 80.0f));
}
