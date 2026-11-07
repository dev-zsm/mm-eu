// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

void ref_func_808B7914(BgBreakwall* this, PlayState* play) {
    s32 pad;
    Vec3f sp30;
    Vec3f sp24;

    if ((play->gameplayFrames % 8) == 0) {
        sp30.x = Rand_ZeroFloat(80.0f) + (this->dyna.actor.world.pos.x - 55.0f);
        sp30.y = this->dyna.actor.world.pos.y + 70.0f;
        sp30.z = Rand_ZeroFloat(80.0f) + (this->dyna.actor.world.pos.z - 130.0f);

        sp24.x = 0.0f;
        sp24.y = 0.5f;
        sp24.z = 0.0f;

        EffectSsIceSmoke_Spawn(play, &sp30, &sp24, &gZeroVec3f, -200 - (s32)(Rand_ZeroOne() * 50.0f));
    }
}
