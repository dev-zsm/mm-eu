// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

s32 ref_func_80A4FEBC(EnDnbEffect* effect, f32 arg1) {
    s32 ret = false;

    if ((DECR(effect->unk_26) == 0) && (arg1 < effect->unk_0C.y)) {
        Math_ApproachF(&effect->unk_30, 1.0f, 0.4f, 1.0f);
        effect->unk_2C += effect->unk_34;
        effect->unk_0C.x += effect->unk_30 * Math_SinS(effect->unk_24);
        effect->unk_0C.z += effect->unk_30 * Math_CosS(effect->unk_24);
        effect->unk_0C.y += effect->unk_2C;
        if (effect->unk_0C.y <= arg1) {
            effect->unk_0C.y = arg1;
        }
        effect->unk_18.x += effect->unk_1E.x;
        effect->unk_18.y += effect->unk_1E.y;
        effect->unk_18.z += effect->unk_1E.z;
        ret = true;
    }

    return ret;
}
