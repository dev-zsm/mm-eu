// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite_old_init.h"

void EffectSsEnFire_SpawnVec3s(PlayState* play, Actor* actor, Vec3s* pos, s16 scale, s16 params, s16 flags,
                               s16 bodyPart) {
    EffectSsEnFireInitParams initParams;

    initParams.pos.x = pos->x;
    initParams.pos.y = pos->y;
    initParams.pos.z = pos->z;
    initParams.actor = actor;
    initParams.scale = scale;
    initParams.params = params;
    initParams.flags = flags | ENFIRE_FLAGS_BODYPART_POS_VEC3S;
    initParams.bodyPart = bodyPart;

    if (actor != NULL) {
        Actor_PlaySfx(actor, NA_SE_EV_FLAME_IGNITION);
    }

    EffectSs_Spawn(play, EFFECT_SS_EN_FIRE, 128, &initParams);
}
