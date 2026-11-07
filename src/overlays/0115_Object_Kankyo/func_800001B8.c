// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DC038(ObjectKankyo* this, PlayState* play) {
    s16 i;

    this->unk_144 = Rand_ZeroOne() * 360.0f;
    this->unk_148 = Rand_ZeroOne() * 360.0f;
    this->unk_114C = 0;

    for (i = 0; i < ARRAY_COUNT(this->unk_14C); i++) {
        this->unk_14C[i].unk_1C = 0;
    }

    ObjectKankyo_SetupAction(this, ref_func_808DCDB4);
}
