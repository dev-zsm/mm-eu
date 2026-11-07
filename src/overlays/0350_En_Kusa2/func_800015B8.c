// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5C718(EnKusa2UnkBssSubStruct* arg0) {
    Math_ScaledStepToS(&arg0->unk_20, arg0->unk_22, 0x4B0);

    if ((arg0->unk_1C > 0.0f) && (Rand_ZeroOne() < 0.05f)) {
        arg0->unk_1C = -arg0->unk_1C;
    }

    arg0->unk_0C.x = Math_SinS(arg0->unk_22) * arg0->unk_18;
    arg0->unk_0C.y += arg0->unk_1C;
    arg0->unk_0C.z = Math_CosS(arg0->unk_22) * arg0->unk_18;

    arg0->unk_00.x += arg0->unk_0C.x;
    arg0->unk_00.y += arg0->unk_0C.y;
    arg0->unk_00.z += arg0->unk_0C.z;
}
