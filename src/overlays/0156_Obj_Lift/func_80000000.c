// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ref_func_8093D3C0(ObjLift* this, PlayState* play) {
    Vec3f pos;
    Vec3f velocity;
    Vec3f* actorPos = &this->dyna.actor.world.pos;
    s32 i;
    s32 rand;
    s32 pad;

    for (i = 0; i < ARRAY_COUNT(ref_D_8093DD60); i++) {
        pos.x = (ref_D_8093DD60[i].x * this->dyna.actor.scale.x) + actorPos->x;
        pos.y = actorPos->y;
        pos.z = (ref_D_8093DD60[i].z * this->dyna.actor.scale.z) + actorPos->z;

        velocity.x = ref_D_8093DD60[i].x * this->dyna.actor.scale.x * 0.8f;
        velocity.y = (Rand_ZeroOne() * 10.0f) + 6.0f;
        velocity.z = ref_D_8093DD60[i].z * this->dyna.actor.scale.z * 0.8f;

        if ((s32)Rand_Next() > 0) {
            rand = 0x40;
        } else {
            rand = 0x20;
        }

        EffectSsKakera_Spawn(play, &pos, &velocity, actorPos, -0x100, rand, 15, 15, 0,
                             ((Rand_ZeroOne() * 50.0f) + 50.0f) * this->dyna.actor.scale.x, 0, 32, 50, -1,
                             OBJECT_D_LIFT, gDampeGraveBrownElevatorDL);
    }
    if (OBJLIFT_GET_1(&this->dyna.actor) == 0) {
        ref_func_800BBFB0(play, &this->dyna.actor.world.pos, 120.0f, 12, 120, 100, 1);
    } else if (OBJLIFT_GET_1(&this->dyna.actor) == 1) {
        ref_func_800BBFB0(play, &this->dyna.actor.world.pos, 60.0f, 8, 60, 100, 1);
    }
}
