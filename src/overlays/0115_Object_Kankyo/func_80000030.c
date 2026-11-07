// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DBEB0(ObjectKankyo* this, PlayState* play) {
    s32 i;

    ref_D_808DE5B0 = 0.0f;
    this->unk_144 = Rand_ZeroOne() * 360.0f;
    this->unk_148 = Rand_ZeroOne() * 360.0f;
    if (play->envCtx.precipitation[PRECIP_SNOW_CUR] == 128) {
        ref_D_808DE5B0 = 1.0f;
        this->unk_114E = 1;

        for (i = 0; i < play->envCtx.precipitation[PRECIP_SNOW_CUR]; i++) {
            this->unk_14C[i].unk_10 = Rand_ZeroOne() * -200.0f;
        }
    } else {
        this->unk_114E = 0;
    }
    ObjectKankyo_SetupAction(this, ref_func_808DCB7C);
}
