// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

void ObjGrass_Init(Actor* thisx, PlayState* play) {
    ObjGrass* this = (ObjGrass*)thisx;
    s32 i;

    Actor_SetScale(&this->actor, 0.4f);

    for (i = 0; i < ARRAY_COUNT(this->grassElemColliders); i++) {
        Collider_InitCylinder(play, &this->grassElemColliders[i].collider);
        Collider_SetCylinder(play, &this->grassElemColliders[i].collider, &this->actor, &sCylinderInit);
    }

    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->unk_3288 = Rand_Next() >> 0x10;
    this->unk_328A = Rand_Next() >> 0x10;
    this->unk_328C = Rand_Next() >> 0x10;
    this->unk_328E = Rand_Next() >> 0x10;
    this->unk_3290 = Rand_Next() >> 0x10;
}
