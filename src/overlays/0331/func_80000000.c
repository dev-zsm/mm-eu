// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sekihi.h"

void EnSekihi_Init(Actor* thisx, PlayState* play) {
    EnSekihi* this = (EnSekihi*)thisx;
    s32 type = ENSIKIHI_GET_TYPE(thisx);
    s32 objectSlot;
    s32 pad;

    if (((type < SEKIHI_TYPE_0) || (type >= SEKIHI_TYPE_MAX)) || (sOpaDLists[type] == NULL)) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if ((type == SEKIHI_TYPE_4) &&
        ((gSaveContext.save.saveInfo.skullTokenCount & 0xFFFF) >= SPIDER_HOUSE_TOKENS_REQUIRED)) {
        
        SET_WEEKEVENTREG(WEEKEVENTREG_OCEANSIDE_SPIDER_HOUSE_BUYER_MOVED_IN);
    }

    objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[type]);
    if (objectSlot > OBJECT_SLOT_NONE) {
        this->objectSlot = objectSlot;
    }
    this->actionFunc = ref_func_80A44DE8;
    this->opaDList = sOpaDLists[type];
    this->xluDList = sXluDLists[type];
    this->dyna.actor.textId = sTextIds[type];
    this->dyna.actor.focus.pos.y = this->dyna.actor.world.pos.y + 60.0f;
    Actor_SetScale(&this->dyna.actor, 0.1f);
}
