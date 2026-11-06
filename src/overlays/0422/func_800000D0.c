// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_lotus.h"

void ref_func_80AD6830(BgLotus* this) {
    f32 temp_fv1;

    if (this->dyna.actor.params == 0) {
        temp_fv1 = Math_SinF(this->unk166 * (M_PIf / 4)) * ((0.014f * (this->unk166 / (80.0f * 0.1f))) + 0.01f);
        this->dyna.actor.scale.x = (1.0f + temp_fv1) * 0.1f;
        this->dyna.actor.scale.z = (1.0f - temp_fv1) * 0.1f;
    }
}
