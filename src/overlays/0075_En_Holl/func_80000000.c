// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_SetupAction(EnHoll* this) {
    this->type = EN_HOLL_GET_TYPE(&this->actor);
    this->actionFunc = sActionFuncs[this->type];
    if (EN_HOLL_IS_VISIBLE(this)) {
        this->alpha = 255;
    } else {
        this->actor.draw = NULL;
    }
}
