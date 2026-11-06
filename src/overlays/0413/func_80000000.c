// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ref_func_80ACB6A0(ObjAqua* this, PlayState* play) {
    s32 pad;
    Vec3f sp58;
    s32 angleOffset = 0;
    s32 i;

    sp58.y = this->actor.world.pos.y + this->actor.depthInWater;
    for (i = 0; i < 4; i++) {
        sp58.x = this->actor.world.pos.x + Math_SinS((s32)(Rand_ZeroOne() * 7200.0f) + angleOffset) * 8.0f;
        sp58.z = this->actor.world.pos.z + Math_CosS((s32)(Rand_ZeroOne() * 7200.0f) + angleOffset) * 8.0f;
        EffectSsGSplash_Spawn(play, &sp58, NULL, NULL, 0, 120);
        angleOffset += 0x4000;
    }
    sp58.x = this->actor.world.pos.x;
    sp58.z = this->actor.world.pos.z;
    EffectSsGSplash_Spawn(play, &sp58, NULL, NULL, 0, 300);
}
