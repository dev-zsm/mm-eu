// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ObjHugebombiwa_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjHugebombiwa* this = (ObjHugebombiwa*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitCylinder(play, &this->collider);

    if (Flags_GetSwitch(play, ENHUGEBOMBIWA_GET_SWITCH_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
        return;
    }

    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    if ((ENHUGEBOMBIWA_GET_100(&this->actor)) == 1) {
        this->actor.draw = ref_func_80A55B34;
        Actor_SetScale(&this->actor, 0.74f);
        this->collider.dim.radius = 204;
        this->collider.dim.height = 230;
    } else {
        Actor_SetScale(&this->actor, 0.067f);
        this->collider.dim.radius = 120;
        this->collider.dim.height = 151;
    }
    ref_func_80A54BF0(this);
}
