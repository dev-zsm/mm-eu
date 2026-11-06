// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ref_func_80ACB7F4(ObjAqua* this, PlayState* play) {
    s32 pad;
    Vec3f effectPos;
    s32 angleOffset = 0;
    s32 i;

    effectPos.y = this->actor.floorHeight;
    for (i = 0; i < 4; i++) {
        effectPos.x = this->actor.world.pos.x + Math_SinS((s32)(Rand_ZeroOne() * 7200.0f) + angleOffset) * 8.0f;
        effectPos.z = this->actor.world.pos.z + Math_CosS((s32)(Rand_ZeroOne() * 7200.0f) + angleOffset) * 8.0f;
        EffectSsGSplash_Spawn(play, &effectPos, NULL, NULL, 0, 120);
        angleOffset += 0x4000;
    }
    effectPos.x = this->actor.world.pos.x;
    effectPos.z = this->actor.world.pos.z;
    EffectSsGSplash_Spawn(play, &effectPos, NULL, NULL, 0, 300);
}
