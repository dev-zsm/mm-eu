// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_TowerOpening_DropCounterweight(ObjTokeidai* this, PlayState* play) {
    this->xRotation += this->counterweightAngularVelocity;
    if (this->xRotation < 0x4000) {
        this->counterweightAngularVelocity += this->counterweightRotationalAcceleration;
        return;
    }

    this->counterweightRotationalAcceleration = 0x14;
    this->xRotation = 0x4000;
    switch (this->boundCount) {
        case 0:
            Actor_PlaySfx(&this->actor, NA_SE_EV_CLOCK_TOWER_BOUND_0);
            break;

        case 1:
            Actor_PlaySfx(&this->actor, NA_SE_EV_CLOCK_TOWER_BOUND_1);
            break;

        case 2:
            Actor_PlaySfx(&this->actor, NA_SE_EV_CLOCK_TOWER_BOUND_2);
            break;

        default:
            break;
    }
    this->boundCount++;

    if (this->counterweightAngularVelocity > 0x190) {
        
        
        this->counterweightAngularVelocity = -0xC8;
    } else if (this->counterweightAngularVelocity > 0x32) {
        
        
        this->counterweightAngularVelocity = -(this->counterweightAngularVelocity >> 1);
    } else {
        
        
        this->actionFunc = ObjTokeidai_TowerOpening_Wait;
        this->openingWaitTimer = 10;
    }
}
