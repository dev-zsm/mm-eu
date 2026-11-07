// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_AddAndChooseFeather(OwlWarpFeather* feathers, Vec3f* pos, s32 isPosYRand) {
    static s32 sFeatherIndex = 0;
    s32 i;
    s32 featherAdded = false;
    OwlWarpFeather* feather;
    s32 featherIndex;

    for (i = 0, feather = feathers; i < OWL_WARP_NUM_FEATHERS; i++, feather++) {
        if (feather->type == OWL_WARP_FEATHER_TYPE_DISABLED) {
            EnTest7_AddFeather(feather, pos, isPosYRand);
            sFeatherIndex = i;
            featherAdded = true;
            break;
        }
    }

    if (!featherAdded) {
        featherIndex = sFeatherIndex + 1;
        if (featherIndex >= OWL_WARP_NUM_FEATHERS) {
            featherIndex = 0;
        }

        EnTest7_AddFeather(&feathers[featherIndex], pos, isPosYRand);
    }
}
