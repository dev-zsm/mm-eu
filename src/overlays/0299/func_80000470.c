// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1B840(MtxF* matrix) {
    MtxF* temp = Matrix_GetCurrent();
    f32* tmp = &temp->xx;
    f32* tmp2 = &matrix->xx;
    s32 i;

    for (i = 0; i < 16; i++) {
        *tmp++ += *tmp2++;
    }
}
