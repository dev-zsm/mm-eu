// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test2.h"

void EnTest2_Init(Actor* thisx, PlayState* play) {
    EnTest2* this = (EnTest2*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    if ((ENTEST2_GET_TYPE(&this->actor) == EN_TEST2_TYPE_11) || (ENTEST2_GET_TYPE(&this->actor) == EN_TEST2_TYPE_12)) {
        this->actor.flags |= ACTOR_FLAG_DRAW_CULLING_DISABLED;
    }
}
