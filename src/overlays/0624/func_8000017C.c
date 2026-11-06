// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

void ref_func_80C07DFC(Vec3f* arg0, Vec3s* arg1, Vec3f* arg2, Vec3s* arg3, s32 arg4, s32 arg5, Vec3f* arg6, Vec3s* arg7) {
    f32 temp_fv0 = (f32)arg4 / arg5;

    
    arg6->x = ((arg2->x - arg0->x) * temp_fv0) + arg0->x;
    arg6->y = ((arg2->y - arg0->y) * temp_fv0) + arg0->y;
    arg6->z = ((arg2->z - arg0->z) * temp_fv0) + arg0->z;
    arg7->x = (((f32)arg3->x - (f32)arg1->x) * temp_fv0) + arg1->x;
    arg7->y = (((f32)arg3->y - (f32)arg1->y) * temp_fv0) + arg1->y;
    arg7->z = (((f32)arg3->z - (f32)arg1->z) * temp_fv0) + arg1->z;
}
