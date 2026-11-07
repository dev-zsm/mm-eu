// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_invisible_ruppe.h"

void EnInvisibleRuppe_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnInvisibleRuppe* this = (EnInvisibleRuppe*)thisx;

    this->switchFlag = INVISIBLERUPPE_GET_SWITCH_FLAG(&this->actor);

    if (this->switchFlag == INVISIBLERUPPE_SWITCH_FLAG_NONE) {
        this->switchFlag = SWITCH_FLAG_NONE;
    }

    if ((this->switchFlag > SWITCH_FLAG_NONE) && Flags_GetSwitch(play, this->switchFlag)) {
        Actor_Kill(&this->actor);
        return;
    }

    Collider_InitCylinder(play, &this->collider);
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

    this->actionFunc = ref_func_80C2590C;
}
