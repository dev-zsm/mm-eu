// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_carry.h"

void ObjGrassCarry_Destroy(Actor* thisx, PlayState* play) {
    ObjGrassCarry* this = (ObjGrassCarry*)thisx;

    Collider_DestroyCylinder(play, &this->collider);

    if (this->grassManager != NULL) {
        ObjGrassCarry** carry = &this->grassManager->grassCarry[this->actor.params];

        if (this == *carry) {
            *carry = NULL;
            this->grassManager = NULL;
        }
    }
}
