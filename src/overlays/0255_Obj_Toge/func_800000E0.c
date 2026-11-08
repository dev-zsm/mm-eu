// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

void ref_func_809A42A0(ObjToge* this, PlayState* play) {
    Vec3f sp54;
    s32 i;
    s16 phi_s0;

    sp54.y = this->actor.world.pos.y + 15.0f;

    for (i = 0, phi_s0 = 0; i < 5; i++, phi_s0 += 0x3333) {
        sp54.x = (Math_SinS(phi_s0) * 15.0f) + this->actor.world.pos.x;
        sp54.z = (Math_CosS(phi_s0) * 15.0f) + this->actor.world.pos.z;
        ref_func_800B2B44(play, &this->actor, &sp54, (Rand_ZeroOne() * 0.6f) + 2.8f);
    }
}
