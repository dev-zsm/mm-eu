// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

s32 ObjMine_StepUntilParallel(Vec3f* value, Vec3f* target, f32 angleStep) {
    Vec3f perpVec;
    Vec3f prevValue;
    Vec3f perpNormal;
    f32 cosAngle = Math3D_Cos(value, target);

    if (Math_CosF(angleStep) <= cosAngle) {
        Math_Vec3f_Copy(value, target);
        return true;
    }

    Matrix_Push();
    Math_Vec3f_Copy(&prevValue, value);
    Math3D_Vec3f_Cross(value, target, &perpVec);
    if (ObjMine_GetUnitVec3f(&perpVec, &perpNormal)) {
        Matrix_RotateAxisS(RAD_TO_BINANG(angleStep), &perpNormal, MTXMODE_NEW);
        Matrix_MultVec3f(&prevValue, value);
    } else {
        Matrix_RotateXFNew(angleStep);
        Matrix_MultVec3f(&prevValue, value);
    }

    Matrix_Pop();
    return false;
}
