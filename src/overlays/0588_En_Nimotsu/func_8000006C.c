// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_nimotsu.h"

void EnNimotsu_Init(Actor* thisx, PlayState* play) {
    EnNimotsu* this = (EnNimotsu*)thisx;

    Collider_InitCylinder(play, &this->collider);
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

    this->timer = 10;
    this->actor.gravity = -0.5f;

    Actor_SetScale(&this->actor, 0.01f);
}
