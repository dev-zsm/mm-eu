// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_Init(Actor* thisx, PlayState* play) {
    s32 params;
    EnHonotrap* this = (EnHonotrap*)thisx;

    params = this->actor.params;
    Actor_ProcessInitChain(&this->actor, sInitChain);
    if ((params == HONOTRAP_TYPE_EYE) || (params == HONOTRAP_TYPE_EYE_MUTI_FLAME)) {
        EnHonotrap_InitEye(this, play);
    } else if (params == HONOTRAP_TYPE_FLAME_GROUP) {
        EnHonotrap_InitFlameGroup(this, play);
        this->actor.update = EnHonotrap_UpdateFlameGroup;
        this->actor.draw = EnHonotrap_DrawFlameGroup;
        this->actor.cullingVolumeScale = 500.0f;
        this->actor.cullingVolumeDownward = 500.0f;
    } else { 
        EnHonotrap_InitFlame(this, play);
        this->actor.update = EnHonotrap_UpdateFlame;
        this->actor.draw = EnHonotrap_DrawFlame;
    }
}
