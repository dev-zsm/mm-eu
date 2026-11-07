// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_RisingDebris_UpdateEffects(EnFall* this) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(debrisEffects); i++) {
        if (debrisEffects[i].modelIndex < 3) {
            debrisEffects[i].pos.x += debrisEffects[i].velocity.x;
            debrisEffects[i].pos.y += debrisEffects[i].velocity.y;
            debrisEffects[i].pos.z += debrisEffects[i].velocity.z;
            debrisEffects[i].rot.x += 0x64;
            debrisEffects[i].rot.y += 0xC8;
            debrisEffects[i].rot.z += 0x12C;
            if ((this->actor.world.pos.y + 3000.0f) < debrisEffects[i].pos.y) {
                debrisEffects[i].modelIndex = 3;
                this->activeDebrisEffectCount--;
            }
        }
    }
}
