// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

void EnDnb_Draw(Actor* thisx, PlayState* play) {
    EnDnb* this = (EnDnb*)thisx;

    if (play->actorCtx.lensMaskSize != 0) {
        ref_func_80A50510(this, play);
    } else {
        ref_func_80A5063C(this, play);
    }
    ref_func_80A50950(this->unk_0D38, play);
}
