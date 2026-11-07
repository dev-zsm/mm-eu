// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A24B74(ObjIceblock* this, PlayState* play) {
    s32 pad;
    Vec3f sp20;

    if (!(this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
        return;
    }

    sp20.x = this->dyna.actor.world.pos.x;
    sp20.y = this->unk_244;
    sp20.z = this->dyna.actor.world.pos.z;
    EffectSsGRipple_Spawn(play, &sp20, 480, 880, 0);
}
