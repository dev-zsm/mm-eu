// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_col_man.h"

void ref_func_80AFDF60(EnColMan* this) {
    this->actor.draw = ref_func_80AFE584;
    this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    this->actor.flags |= ACTOR_FLAG_DRAW_CULLING_DISABLED;
    this->type = EN_COL_MAN_FALLING_ROCK;
    this->actionFunc = ref_func_80AFDFB4;
    this->actor.shape.shadowScale = 5.0f;
    this->actor.gravity = -3.0f;
}
