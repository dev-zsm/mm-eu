// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dy_extra.h"

void EnDyExtra_Init(Actor* thisx, PlayState* play) {
    EnDyExtra* this = (EnDyExtra*)thisx;

    this->type = this->actor.params;
    this->actor.scale.x = 0.025f;
    this->actor.scale.y = 0.039f;
    this->actor.scale.z = 0.025f;
    this->initPos = this->actor.world.pos;
    this->actor.gravity = -0.2f;
    this->alphaScale = 1.0f;
    this->timer = 60;
    this->actionFunc = EnDyExtra_WaitForTrigger;
}
