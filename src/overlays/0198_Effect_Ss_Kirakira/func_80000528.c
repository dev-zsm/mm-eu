// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kirakira.h"

void ref_func_80977F28(PlayState* play, u32 index, EffectSs* this) {
    this->rScale = this->rEnvColorA * Math_SinS((32768.0f / this->rLifespan) * this->life);
}
