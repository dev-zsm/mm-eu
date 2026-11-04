// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_estone.h"

void EnEstone_UpdateEffects(EnEstone* this, PlayState* play) {
    EnEstoneEffect* effect = this->effects;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->effects); i++, effect++) {
        if (effect->isActive) {
            effect->rot.x += 0x100;
            effect->rot.z += 0x130;

            effect->pos.x += effect->velocity.x;
            effect->pos.y += effect->velocity.y;
            effect->pos.z += effect->velocity.z;

            effect->velocity.y += effect->accel.y;
            if ((effect->pos.y < this->actor.floorHeight) && (effect->velocity.y < 0.0f)) {
                effect->timer = 0;
                Actor_SpawnFloorDustRing(play, &this->actor, &effect->pos, 0.0f, 5, 3.0f, 30, 15, true);
            }
            if (effect->timer != 0) {
                effect->timer--;
            } else {
                effect->isActive = false;
            }
        }
    }
}
