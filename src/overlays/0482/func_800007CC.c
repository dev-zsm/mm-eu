// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B395EC(Actor* thisx, PlayState* play) {
    ObjSnowball2* this = (ObjSnowball2*)thisx;
    Vec3f sp18;

    sp18.x = this->actor.world.pos.x;
    sp18.y = this->actor.world.pos.y + this->actor.depthInWater;
    sp18.z = this->actor.world.pos.z;
    ref_func_80B395C4(play, &sp18);
}
