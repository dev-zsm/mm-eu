// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5D62C(EnKusa2* this, PlayState* play) {
    if (this->unk_1BE != 0) {
        ref_func_80A5B490(this, play);
        ref_func_80A5D754(this);
    } else if (Math3D_Dist1DSq(this->actor.projectedPos.x, this->actor.projectedPos.z) < SQ(1600.0f)) {
        ref_func_80A5B160(this, play);
        ref_func_80A5D6B0(this);
    }
}
