// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_danpei_movebg.h"

void ref_func_80AF746C(BgDanpeiMovebg* this, PlayState* play) {
    this->flags = ref_func_80AF705C(this, this->flags);
    if (!(this->flags & (DANPEI_MOVEBG_FLAG_8 | DANPEI_MOVEBG_FLAG_10))) {
        if (this->actorPath.flags & ACTOR_PATHING_MOVE_BACKWARDS) {
            this->actionFunc = ref_func_80AF7354;
        } else {
            this->actionFunc = ref_func_80AF71FC;
        }
    }
}
