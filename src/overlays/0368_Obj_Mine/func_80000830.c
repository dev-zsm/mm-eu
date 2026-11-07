// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_SetBasis(ObjMine* this) {
    ObjMineAirChain* airChain = &this->chain.air;
    Vec3f tempVec;

    tempVec.x = -airChain->displacement.x;
    tempVec.y = 1.0f;
    tempVec.z = -airChain->displacement.z;

    ObjMine_GetUnitVec3f(&tempVec, &airChain->basis.y);

    Math3D_Vec3f_Cross(&sStandardBasis.x, &airChain->basis.y, &tempVec);
    ObjMine_GetUnitVec3f(&tempVec, &airChain->basis.z);

    Math3D_Vec3f_Cross(&airChain->basis.y, &airChain->basis.z, &tempVec);
    ObjMine_GetUnitVec3f(&tempVec, &airChain->basis.x);
}
