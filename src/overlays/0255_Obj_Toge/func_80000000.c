// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

void ref_func_809A41C0(ObjToge* this, PlayState* play) {
    Vec3f sp1C = this->actor.world.pos;

    sp1C.y += 10.0f;
    sp1C.z += 10.0f;
    ref_func_800B2B44(play, &this->actor, &sp1C, 1.8f);

    sp1C.x += 10.0f;
    sp1C.z -= 20.0f;
    ref_func_800B2B44(play, &this->actor, &sp1C, 1.8f);

    sp1C.x -= 20.0f;
    ref_func_800B2B44(play, &this->actor, &sp1C, 1.8f);
}
