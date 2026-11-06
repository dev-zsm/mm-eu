// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void ref_func_80B9E7D0(MirRay3Struct* ptr) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = i + 1; j < 6; j++) {
            if ((ptr[i].unk_4C != NULL) && (ptr[j].unk_4C != NULL)) {
                if ((ABS(ptr[i].unk_4C->normal.x - ptr[j].unk_4C->normal.x) < 100) &&
                    (ABS(ptr[i].unk_4C->normal.y - ptr[j].unk_4C->normal.y) < 100) &&
                    (ABS(ptr[i].unk_4C->normal.z - ptr[j].unk_4C->normal.z) < 100) &&
                    (ptr[i].unk_4C->dist == ptr[j].unk_4C->dist)) {
                    ptr[j].unk_4C = NULL;
                }
            }
        }
    }
}
