// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80942604(EnGoroiwa* this, PlayState* play) {
    s32 pad;
    s16 sp22 = this->actor.shape.shadowAlpha;

    Math_StepToS(&sp22, 0, 40);
    this->actor.shape.shadowAlpha = sp22;
    if (this->unk_1C8 > 0) {
        this->unk_1C8--;
    } else {
        Actor_Kill(&this->actor);
    }
}
