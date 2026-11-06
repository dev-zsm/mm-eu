// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B80358(Vec3f* arg0) {
    arg0->x += (arg0->x >= 0.0f) ? 0.5f : -0.5f;
    arg0->y += (arg0->y >= 0.0f) ? 0.5f : -0.5f;
    arg0->z += (arg0->z >= 0.0f) ? 0.5f : -0.5f;

    arg0->x = (s32)arg0->x;
    arg0->y = (s32)arg0->y;
    arg0->z = (s32)arg0->z;
}
