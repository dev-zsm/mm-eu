// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ice_poly.h"

void ObjIcePoly_Destroy(Actor* thisx, PlayState* play) {
    ObjIcePoly* this = (ObjIcePoly*)thisx;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->colliders1); i++) {
        Collider_DestroyCylinder(play, &this->colliders1[i]);
        Collider_DestroyCylinder(play, &this->colliders2[i]);
    }
}
