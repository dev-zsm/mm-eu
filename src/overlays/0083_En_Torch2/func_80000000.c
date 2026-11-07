// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_torch2.h"

void EnTorch2_Init(Actor* thisx, PlayState* play) {
    EnTorch2* this = (EnTorch2*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

    if (this->actor.params != TORCH2_PARAM_DEKU) {
        this->actor.flags |= ACTOR_FLAG_CAN_PRESS_SWITCHES;
        if (this->actor.params == TORCH2_PARAM_GORON) {
            this->actor.flags |= ACTOR_FLAG_CAN_PRESS_HEAVY_SWITCHES;
        }
    }
    this->framesUntilNextState = 20;
}
