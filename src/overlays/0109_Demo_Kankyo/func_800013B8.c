// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_kankyo.h"

void DemoKankyo_Init(Actor* thisx, PlayState* play) {
    DemoKankyo* this = (DemoKankyo*)thisx;
    s32 pad;
    s32 i;
    s32 objectSlot;

    
    
    for (i = 0; i < ARRAY_COUNT(this->effects); i++) { this->effects[i].state = DEMO_KANKYO_STATE_INIT; }
    

    
    if (1) {}

    switch (this->actor.params) {
        case DEMO_KANKYO_TYPE_LOSTWOODS:
            objectSlot = 0;
            this->actor.room = -1;
            if (sLostWoodsSparklesMutex == false) {
                DemoKankyo_SetupAction(this, DemoKakyo_LostWoodsSparkleActionFunc);
                sLostWoodsSparklesMutex = true;
            } else {
                Actor_Kill(&this->actor);
            }
            break;

        case DEMO_KANKYO_TYPE_GIANTS:
            this->isSafeToDrawGiants = false;
            objectSlot = Object_GetSlot(&play->objectCtx, sObjectBubbleId);
            DemoKankyo_SetupAction(this, DemoKakyo_GiantObjectCheck);
            break;

        case DEMO_KANKYO_TYPE_MOON:
            objectSlot = 0;
            this->isSafeToDrawGiants = true;
            DemoKankyo_SetupAction(this, DemoKakyo_MoonSparklesActionFunc);
            break;

        default:
            
            objectSlot = OBJECT_SLOT_NONE;
            break;
    }

    if (objectSlot > OBJECT_SLOT_NONE) {
        this->objectSlot = objectSlot;
    }
}
