// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

void ObjGrass_Destroy(Actor* thisx, PlayState* play) {
    ObjGrass* this = (ObjGrass*)thisx;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->grassElemColliders); i++) {
        Collider_DestroyCylinder(play, &this->grassElemColliders[i].collider);
    }

    for (i = 0; i < ARRAY_COUNT(this->grassCarry); i++) {
        ObjGrassCarry** grassCarry = &this->grassCarry[i];

        if (*grassCarry != NULL) {
            (*grassCarry)->grassManager = NULL;
            *grassCarry = NULL;
        }
    }
}
