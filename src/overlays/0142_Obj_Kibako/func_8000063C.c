// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ObjKibako_WaterBreak(ObjKibako* this, PlayState* play) {
    s16 angle;
    s32 i;
    Vec3f* worldPos = &this->actor.world.pos;
    Vec3f pos;
    Vec3f velocity;

    pos.y = worldPos->y + this->actor.depthInWater;
    for (angle = 0, i = 0; i < 5; i++, angle += 0x3333) {
        pos.x = worldPos->x + (Math_SinS(((s32)(Rand_ZeroOne() * 6000.0f)) + angle) * 15.0f);
        pos.z = worldPos->z + (Math_CosS(((s32)(Rand_ZeroOne() * 6000.0f)) + angle) * 15.0f);
        EffectSsGSplash_Spawn(play, &pos, NULL, NULL, 0, 350);
    }
    pos.x = worldPos->x;
    pos.z = worldPos->z;
    EffectSsGRipple_Spawn(play, &pos, 200, 600, 0);

    for (i = 0, angle = 0; i < 12; i++, angle += 0x4E20) {
        f32 sn = Math_SinS(angle);
        f32 cs = Math_CosS(angle);
        f32 temp_rand;
        s16 phi_s0;

        pos.x = sn * 16.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = cs * 16.0f;
        velocity.x = pos.x * 0.18f;
        velocity.y = (Rand_ZeroOne() * 4.0f) + 2.0f;
        velocity.z = pos.z * 0.18f;
        pos.x += worldPos->x;
        pos.y += worldPos->y;
        pos.z += worldPos->z;
        temp_rand = Rand_ZeroOne();
        phi_s0 = (temp_rand < 0.2f) ? 0x40 : 0x20;

        EffectSsKakera_Spawn(play, &pos, &velocity, worldPos, -180, phi_s0, 50, 5, 0, (Rand_ZeroOne() * 35.0f) + 10.0f,
                             0, 0, 70, -1, sObjectIds[KIBAKO_BANK_INDEX(&this->actor)],
                             sKakeraDisplayLists[KIBAKO_BANK_INDEX(&this->actor)]);
    }
}
