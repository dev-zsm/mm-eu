// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25994(ObjIceblock* this, PlayState* play) {
    s32 pad;
    Vec3f sp30;

    ref_func_80A236D4(this, &this->dyna.actor.home.pos);
    if (this->stateTimer > 0) {
        this->stateTimer--;
        return;
    }

    if (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        ref_func_80A2339C(play, &this->dyna.actor.world.pos, this->dyna.actor.scale.x, 1.2f, 15);
        if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor)) {
            sp30.x = this->dyna.actor.world.pos.x;
            sp30.y = this->dyna.actor.world.pos.y - 30.0f;
            sp30.z = this->dyna.actor.world.pos.z;
            ref_func_80A2339C(play, &sp30, this->dyna.actor.scale.x, 1.2f, 10);
        }
    }

    if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor)) {
        this->unk_2B4 = 0.1f;
    }

    ref_func_80A25A8C(this);
    this->extendedDrawFunc = ref_func_80A26B74;
}
