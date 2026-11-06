// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B145F4(ObjHakaisi* this) {
    this->unk_19A = 0;
    this->dyna.actor.flags |= ACTOR_FLAG_LOCK_ON_DISABLED;
    this->dyna.actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WALL_BROKEN);
    this->actionFunc = ref_func_80B14648;
}
