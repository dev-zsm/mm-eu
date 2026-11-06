// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_extra.h"

u32 EffectSsExtra_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    s32 pad;
    EffectSsExtraInitParams* params = PARAMS;
    s32 objectSlot;

    objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_YABUSAME_POINT);
    if ((objectSlot > OBJECT_SLOT_NONE) && Object_IsLoaded(&play->objectCtx, objectSlot)) {
        uintptr_t segBackup = gSegments[0x06];

        gSegments[0x06] = OS_K0_TO_PHYSICAL(play->objectCtx.slots[objectSlot].segment);

        this->pos = params->pos;
        this->velocity = params->velocity;
        this->accel = params->accel;
        this->draw = EffectSsExtra_Draw;
        this->update = EffectSsExtra_Update;
        this->life = 50;
        this->rScoreIndex = params->scoreIndex;
        this->rScale = params->scale;
        this->rTimer = 5;
        this->rObjectSlot = objectSlot;

        gSegments[0x06] = segBackup;
        return 1;
    }
    return 0;
}
