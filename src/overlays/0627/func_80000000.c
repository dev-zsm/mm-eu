// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_milk_bin.h"

void ObjMilkBin_Init(Actor* thisx, PlayState* play) {
    ObjMilkBin* this = (ObjMilkBin*)thisx;

    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->actor, &this->collider);

    this->actor.shape.yOffset = 1100.0f;
    this->disableDraw = 0;
    this->type = thisx->params;

    if ((this->type == OBJ_MILK_BIN_TYPE_2) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_ESCORTED_CREMIA)) {
        this->disableDraw |= 1;
    }
}
