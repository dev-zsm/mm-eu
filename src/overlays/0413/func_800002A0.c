// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ref_func_80ACB940(ObjAqua* this, PlayState* play) {
    s32 pad;
    Vec3f effectPos;
    Vec3f effectVelocity;

    effectVelocity.x = Rand_ZeroOne() - 0.5f;
    effectVelocity.y = 2.0f;
    effectVelocity.z = Rand_ZeroOne() - 0.5f;
    effectPos.x = this->actor.world.pos.x + (effectVelocity.x * 40.0f);
    effectPos.y = this->actor.world.pos.y;
    effectPos.z = this->actor.world.pos.z + (effectVelocity.z * 40.0f);
    EffectSsIceSmoke_Spawn(play, &effectPos, &effectVelocity, &gZeroVec3f, (s32)(Rand_ZeroOne() * 24.0f) + 70);
}
