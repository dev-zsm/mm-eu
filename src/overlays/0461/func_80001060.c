// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B151E0(ObjHakaisi* this, PlayState* play) {
    this->dyna.actor.update = ref_func_80B1544C;
    this->dyna.actor.draw = ref_func_80B154A0;
    this->dyna.actor.destroy = ref_func_80B15254;
    Actor_SetScale(&this->dyna.actor, 0.1f);
    this->dyna.actor.shape.yOffset = 100.0f;
    this->dyna.actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    ref_func_80B15264(this);
}
