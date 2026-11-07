// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Init(Actor* thisx, PlayState* play) {
    EnFall* this = (EnFall*)thisx;
    s32 objectSlot;

    this->eyeGlowIntensity = 0.0f;
    this->flags = 0;

    
    
    switch (EN_FALL_SCALE(&this->actor)) {
        case 1:
            this->scale = 0.08f;
            break;

        case 2:
            this->scale = 0.04f;
            break;

        case 3:
            this->scale = 0.02f;
            break;

        case 4:
            this->scale = 0.01f;
            break;

        default:
            this->scale = 0.16f;
            break;
    }

    switch (EN_FALL_TYPE(&this->actor)) {
        case EN_FALL_TYPE_LODMOON_NO_LERP:
        case EN_FALL_TYPE_LODMOON:
        case EN_FALL_TYPE_LODMOON_INVERTED_STONE_TOWER:
            objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_LODMOON);
            break;

        case EN_FALL_TYPE_MOONS_TEAR:
            objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_MOONSTON);
            break;

        case EN_FALL_TYPE_STOPPED_MOON_OPEN_MOUTH:
            objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_FALL2);
            break;

        default:
            objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_FALL);
            break;
    }

    if (objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->actor);
        return;
    }
    this->objectSlot = objectSlot;
    this->actionFunc = EnFall_Setup;
}
