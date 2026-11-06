// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_Init(Actor* thisx, PlayState* play) {
    EnHoll* this = (EnHoll*)thisx;
    s32 pad;
    Vec3f transformedPlayerPos;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    EnHoll_SetupAction(this);
    this->bgCoverAlphaActive = false;
    this->alpha = 255;
    EnHoll_SetPlayerSide(play, this, &transformedPlayerPos);
}
