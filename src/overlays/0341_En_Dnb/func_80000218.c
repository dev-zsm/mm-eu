// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

void ref_func_80A4FFE8(EnDnbEffect* effect, s16 arg1) {
    effect->unk_0C = effect->unk_00;
    effect->unk_1E.x = (Rand_ZeroOne() - 0.5f) * 400.0f;
    effect->unk_1E.y = (Rand_ZeroOne() - 0.5f) * 400.0f;
    effect->unk_1E.z = (Rand_ZeroOne() - 0.5f) * 400.0f;
    effect->unk_18 = gZeroVec3s;
    effect->unk_30 = 40.0f;
    effect->unk_2C = 0.0f;
    effect->unk_26 = arg1;
    effect->unk_34 = (Rand_ZeroOne() * -2.0f) - 2.0f;
}
