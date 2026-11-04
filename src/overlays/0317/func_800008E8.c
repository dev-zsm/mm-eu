// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bell.h"

void ObjBell_Draw(Actor* thisx, PlayState* play) {
    ObjBell* this = (ObjBell*)thisx;
    Vec3f sp30;
    Vec3f sp24;

    ref_func_80A35B18(thisx, play);
    ref_func_80A35BD4(thisx, play);
    ref_func_80A359B4(thisx, play);
    Math_Vec3s_ToVec3f(&sp30, &this->collider1.dim.modelSphere.center);
    Matrix_MultVec3f(&sp30, &sp24);
    Math_Vec3f_ToVec3s(&this->collider1.dim.worldSphere.center, &sp24);
    Math_Vec3s_ToVec3f(&sp30, &this->collider2.dim.modelSphere.center);
    Matrix_MultVec3f(&sp30, &sp24);
    Math_Vec3f_ToVec3s(&this->collider2.dim.worldSphere.center, &sp24);
}
