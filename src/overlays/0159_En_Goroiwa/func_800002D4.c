// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

f32 ref_func_8093EB74(EnGoroiwa* this, PlayState* play) {
    s32 i;
    Path* path = &play->setupPathList[ENGOROIWA_GET_PATH_INDEX(&this->actor)];
    s32 temp_s4 = path->count;
    f32 temp_f20 = 0.0f;
    Vec3f sp54;
    Vec3f sp48;

    Math_Vec3s_ToVec3f(&sp48, &this->pathPoints[0]);

    for (i = 1; i < temp_s4; i++) {
        Math_Vec3f_Copy(&sp54, &sp48);
        Math_Vec3s_ToVec3f(&sp48, &this->pathPoints[i]);
        temp_f20 += Math3D_Vec3f_DistXYZ(&sp54, &sp48);
    }

    return temp_f20;
}
