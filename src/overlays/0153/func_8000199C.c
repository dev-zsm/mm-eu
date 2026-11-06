// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_8093868C(ObjBean* this, PlayState* play) {
    if (this->unk_1B2 <= 0) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (this->unk_1B2 <= 20) {
        this->dyna.actor.scale.x *= 0.89f;
        this->dyna.actor.scale.y *= 0.89f;
        this->dyna.actor.scale.z *= 0.89f;
        this->unk_1B8 *= 0.89f;
    }
}
