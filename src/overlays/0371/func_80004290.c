// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80004290(s16 pitch, s16 yaw, Vec3f* pos, Vec3s* rot, s32 overrideRot) {
    Vec3f newPos;
    Vec3f zeroVec = gZeroVec3f;
    Vec3s newRot;
    MtxF currentState;

    Matrix_MultVec3f(&zeroVec, &newPos);
    Matrix_Get(&currentState);
    Matrix_MtxFToYXZRot(&currentState, &newRot, false);
    *pos = newPos;
    if (overrideRot) {
        newRot.x += pitch;
        newRot.y += yaw;
        Math_SmoothStepToS(&rot->x, newRot.x, 4, 0x1FFE, 1);
        Math_SmoothStepToS(&rot->y, newRot.y, 4, 0x1FFE, 1);
        Math_SmoothStepToS(&rot->z, newRot.z, 4, 0x1FFE, 1);
    } else {
        rot->x = newRot.x;
        rot->y = newRot.y;
        rot->z = newRot.z;
    }
}
