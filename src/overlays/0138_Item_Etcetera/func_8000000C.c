// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_item_etcetera.h"

void ItemEtcetera_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ItemEtcetera* this = (ItemEtcetera*)thisx;
    s32 type = ITEMETCETERA_GET_FF(&this->actor);
    s32 objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[type]);

    if (objectSlot <= OBJECT_SLOT_NONE) {
        
    } else {
        this->objectSlot = objectSlot;
    }
    this->getItemDrawId = sGetItemDrawIds[type];
    this->getItemId = sGetItemIds[type];
    this->futureActionFunc = ref_func_8092009C;
    this->drawFunc = ItemEtcetera_Draw;
    Actor_SetScale(&this->actor, 0.25f);
    ItemEtcetera_SetupAction(this, ItemEtcetera_WaitForObject);
    switch (type) {
        case ITEM_ETC_ARROW_FIRE:
            Actor_SetScale(&this->actor, 0.5f);
            this->actor.draw = NULL;
            this->actor.shape.yOffset = 50.0f;
            break;

        case ITEM_ETC_RUPEE_GREEN_CHEST_GAME:
        case ITEM_ETC_RUPEE_BLUE_CHEST_GAME:
        case ITEM_ETC_RUPEE_RED_CHEST_GAME:
        case ITEM_ETC_RUPEE_PURPLE_CHEST_GAME:
        case ITEM_ETC_HEART_PIECE_CHEST_GAME:
        case ITEM_ETC_KEY_SMALL_CHEST_GAME:
            Actor_SetScale(&this->actor, 0.5f);
            this->futureActionFunc = ref_func_809200F8;
            this->drawFunc = ItemEtcetera_DrawThroughLens;
            this->actor.world.pos.y += 15.0f;
            break;

        default:
            break;
    }
}
