// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ref_func_8098D8C8(ObjComb* this, PlayState* play) {
    s32 params = OBJCOMB_GET_F(&this->actor);
    s32 i;
    s32 phi_s5;

    if (this->actionFunc == ref_func_8098DC60) {
        phi_s5 = 2;
    } else {
        phi_s5 = 1;
    }
    this->unk_1B6 = 0;

    for (i = 0; i < params; i++) {
        if (Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BEE, this->actor.world.pos.x, this->actor.world.pos.y,
                        this->actor.world.pos.z, 0, 0, 0, phi_s5)) {
            this->unk_1B6 = 1;
        }
    }
}
