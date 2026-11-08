// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tubo_trap.h"

void EnTuboTrap_SpawnEffectsOnLand(EnTuboTrap* this, PlayState* play) {
    f32 rand;
    f32 sin;
    f32 cos;
    Vec3f pos;
    Vec3f velocity;
    s32 arg5;
    s16 var;
    s32 i;
    Vec3f* actorPos = &this->actor.world.pos;

    for (i = 0, var = 0; i < 15; i++, var += 20000) {
        sin = Math_SinS(var);
        cos = Math_CosS(var);
        pos.x = sin * 8.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = cos * 8.0f;

        velocity.x = pos.x * 0.23f;
        velocity.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        velocity.z = pos.z * 0.23f;

        pos.x += actorPos->x;
        pos.y += actorPos->y;
        pos.z += actorPos->z;

        rand = Rand_ZeroOne();
        if (rand < 0.2f) {
            arg5 = 0x60;
        } else if (rand < 0.6f) {
            arg5 = 0x40;
        } else {
            arg5 = 0x20;
        }
        EffectSsKakera_Spawn(play, &pos, &velocity, actorPos, -0xF0, arg5, 0x14, 0, 0,
                             ((Rand_ZeroOne() * 85.0f) + 15.0f), 0, 0, 0x3C, -1, GAMEPLAY_DANGEON_KEEP,
                             gameplay_dangeon_keep_DL_018090);
    }

    ref_func_800BBFB0(play, actorPos, 30.0f, 4, 0x14, 0x32, 0);
}
