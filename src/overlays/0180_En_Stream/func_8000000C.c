// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_stream.h"

void EnStream_Init(Actor* thisx, PlayState* play) {
    EnStream* this = (EnStream*)thisx;

    this->size = EN_STREAM_SIZE(&this->actor);
    Actor_ProcessInitChain(&this->actor, sInitChain);
    if (this->size != EN_STREAM_SIZE_NORMAL && this->size == EN_STREAM_SIZE_SMALL) {
        this->actor.scale.y = 0.01f;
    }
    EnStream_SetupAction(this, EnStream_WaitForPlayer);
}
