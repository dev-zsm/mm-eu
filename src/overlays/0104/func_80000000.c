// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wood02.h"

s32 EnWood02_SpawnZoneCheck(EnWood02* this, PlayState* play, Vec3f* arg2) {
    f32 phi_f12;

    SkinMatrix_Vec3fMtxFMultXYZW(&play->viewProjectionMtxF, arg2, &this->actor.projectedPos, &this->actor.projectedW);

    if (this->actor.projectedW == 0.0f) {
        phi_f12 = 1000.0f;
    } else {
        phi_f12 = fabsf(1.0f / this->actor.projectedW);
    }

    if (((-this->actor.cullingVolumeScale < this->actor.projectedPos.z) &&
         (this->actor.projectedPos.z < (this->actor.cullingVolumeDistance + this->actor.cullingVolumeScale)) &&
         (((fabsf(this->actor.projectedPos.x) - this->actor.cullingVolumeScale) * phi_f12) < 1.0f)) &&
        (((this->actor.projectedPos.y + this->actor.cullingVolumeDownward) * phi_f12) > -1.0f) &&
        (((this->actor.projectedPos.y - this->actor.cullingVolumeScale) * phi_f12) < 1.0f)) {
        return true;
    }
    return false;
}
