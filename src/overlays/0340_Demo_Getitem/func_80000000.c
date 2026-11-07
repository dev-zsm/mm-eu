// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_getitem.h"

void DemoGetitem_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    s32 objectSlot;
    s32 itemIndex;
    DemoGetitem* this = (DemoGetitem*)thisx;

    itemIndex = DEMOGETITEM_ITEM_MASK_GREAT_FAIRY;
    if (DEMOGETITEM_GET_F(&this->actor) == 1) {
        itemIndex = DEMOGETITEM_ITEM_SWORD_GREAT_FAIRY;
    }

    Actor_SetScale(&this->actor, 0.25f);
    this->actionFunc = DemoGetitem_Wait;
    this->getItemDrawId = sGetItemDraws[itemIndex];
    this->cueType = sCueTypes[itemIndex];

    objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[itemIndex]);
    if (objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->actor);
        return;
    }

    this->objectSlot = objectSlot;
}
