// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_80000000(Actor* thisx, PlayState* play) {
    static s16 sEffectTypeObjectIds[] = {
        OBJECT_EFC_TW, OBJECT_EFC_TW, OBJECT_EFC_TW, OBJECT_EFC_TW, GAMEPLAY_KEEP,
        GAMEPLAY_KEEP, GAMEPLAY_KEEP, GAMEPLAY_KEEP, GAMEPLAY_KEEP,
    };
    s32 pad;
    DemoEffect* this = (DemoEffect*)thisx;
    s32 type = DEMO_EFFECT_GET_TYPE(&this->actor);
    s32 objectSlot;
    s32 pad2;
    Color_RGB8 lightColors[] = {
        { 200, 200, 0 },  
        { 255, 40, 100 }, 
        { 50, 255, 0 },   
        { 0, 0, 255 },    
        { 255, 255, 80 }, 
    };

    if (sEffectTypeObjectIds[type] == GAMEPLAY_KEEP) {
        objectSlot = 0;
    } else {
        objectSlot = Object_GetSlot(&play->objectCtx, sEffectTypeObjectIds[type]);
    }

    if (objectSlot <= OBJECT_SLOT_NONE) {
        
    } else {
        this->initObjectSlot = objectSlot;
    }

    Actor_SetScale(&this->actor, 0.2f);

    switch (type) {
        case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_LARGE:
        case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_SMALL:
            this->actor.flags |= ACTOR_FLAG_UPDATE_DURING_OCARINA;
            FALLTHROUGH;
        case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_LARGE:
        case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_VERY_LARGE:
            this->initDrawFunc = DemoEffect_DrawTimewarp;
            this->initActionFunc = DemoEffect_SetupTimewarp;
            this->envXluColor[0] = 0;
            this->envXluColor[1] = 100;
            this->envXluColor[2] = 255;
            SkelCurve_Clear(&this->skelCurve);
            this->timer = 0;
            break;

        case DEMO_EFFECT_TYPE_LIGHT_DARK_YELLOW:
        case DEMO_EFFECT_TYPE_LIGHT_PINK:
        case DEMO_EFFECT_TYPE_LIGHT_GREEN:
        case DEMO_EFFECT_TYPE_LIGHT_BLUE:
        case DEMO_EFFECT_TYPE_LIGHT_YELLOW:
            this->envXluColor[0] = lightColors[type - DEMO_EFFECT_TYPE_LIGHT_BASE].r;
            this->envXluColor[1] = lightColors[type - DEMO_EFFECT_TYPE_LIGHT_BASE].g;
            this->envXluColor[2] = lightColors[type - DEMO_EFFECT_TYPE_LIGHT_BASE].b;
            Actor_SetScale(&this->actor, 0.0f);
            this->initDrawFunc = DemoEffect_DrawLight;
            this->initActionFunc = DemoEffect_ExpandLight;
            this->timer = 0;
            break;

        default:
            break;
    }

    ActorShape_Init(&this->actor.shape, 0.0f, NULL, 0.0f);
    this->actionFunc = DemoEffect_WaitForObject;
}
