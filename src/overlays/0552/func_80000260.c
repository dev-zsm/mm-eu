// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_CalculatePotPosition(Vec3f* childPosOut, Vec3s* childRotOut, Vec3f* parentPos, Vec3s* parentRot,
                                  s16 childAngle) {
    Vec3f offset;

    Matrix_RotateYS(parentRot->y, MTXMODE_NEW);
    Matrix_RotateXS(parentRot->x, MTXMODE_APPLY);
    Matrix_RotateZS(parentRot->z, MTXMODE_APPLY);
    Matrix_RotateYS(childAngle, MTXMODE_APPLY);
    Matrix_MultVecX(-280.0f, &offset);

    childPosOut->x = parentPos->x + offset.x;
    childPosOut->y = parentPos->y + offset.y;
    childPosOut->z = parentPos->z + offset.z;
    Math_Vec3s_Copy(childRotOut, parentRot);
    childRotOut->y += childAngle;
}
