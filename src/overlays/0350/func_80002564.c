// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5D6C4(EnKusa2* this, PlayState* play) {
    ref_func_80A5B3BC(this);
    if (this->unk_1BE != 0) {
        ref_func_80A5B490(this, play);
        ref_func_80A5D754(this);
    } else if (Math3D_Dist1DSq(this->actor.projectedPos.x, this->actor.projectedPos.z) > SQ(1750.0f)) {
        ref_func_80A5B334(this, play);
        ref_func_80A5D618(this);
    }
}
