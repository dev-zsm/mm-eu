// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_InitFeathers(OwlWarpFeather* feathers) {
    OwlWarpFeather* feather = feathers;
    s32 i;

    for (i = 0, feather = feathers; i < OWL_WARP_NUM_FEATHERS; i++, feather++) {
        s32 pad;

        feather->type = OWL_WARP_FEATHER_TYPE_DISABLED;
        feather->unk_04 = 0;
        feather->pos.x = 0.0f;
        feather->pos.y = 0.0f;
        feather->pos.z = 0.0f;
        feather->velocity.x = 0.0f;
        feather->velocity.y = 0.0f;
        feather->velocity.z = 0.0f;
        feather->accel.x = 0.0f;
        feather->accel.y = 0.0f;
        feather->accel.z = 0.0f;
        feather->scale = 0.00001f;
        feather->rot.x = 0;
        feather->rot.y = 0;
        feather->rot.z = 0;
        feather->angularVelocity.x = 0;
        feather->angularVelocity.y = 0;
        feather->angularVelocity.z = 0;
    }
}
