// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B81570(BgIkanaRotaryroom* this, PlayState* play) {
    s32 i;
    Vec3f sp70;
    Vec3f sp64;
    s32 pad;
    s32 pad2;

    Matrix_Push();
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);

    for (i = 0; i < ARRAY_COUNT(ref_D_80B821C4); i++) {
        sp64.x = ref_D_80B821C4[i].x;
        sp64.y = ref_D_80B821C4[i].y;
        sp64.z = ref_D_80B821C4[i].z;

        Matrix_MultVec3f(&sp64, &sp70);

        sp70.x += this->dyna.actor.world.pos.x;
        sp70.y += this->dyna.actor.world.pos.y;
        sp70.z += this->dyna.actor.world.pos.z;

        Actor_Spawn(&play->actorCtx, play, ACTOR_EN_WATER_EFFECT, sp70.x, sp70.y, sp70.z, 0, 0, 0,
                    ENWATEREFFECT_TYPE_FALLING_ROCK_SPAWNER);
    }

    Matrix_Pop();
}
