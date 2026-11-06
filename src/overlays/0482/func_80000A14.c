// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B39834(Actor* thisx, PlayState* play) {
    ObjSnowball2* this = (ObjSnowball2*)thisx;
    s32 i;

    for (i = 0; i < 3; i++) {
        EffectSsBubble_Spawn(play, &this->actor.world.pos, 0.0f, 20.0f, 30.0f, (Rand_ZeroOne() * 0.11f) + 0.03f);
    }
}
