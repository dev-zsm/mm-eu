// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_egblock.h"

void EnEgblock_Active(EnEgblock* this, PlayState* play) {
    if (this->dyna.actor.colChkInfo.health <= 0) {
        s32 i;

        
        for (i = 0; i < ARRAY_COUNT(this->effects); i++) {
            EnEgblock_SpawnEffect(this, &this->dyna.actor.world.pos, 30, (i & 1) + EGBLOCK_EFFECT_DEBRIS_FLAT);
        }
        DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
        Actor_SpawnFloorDustRing(play, &this->dyna.actor, &this->dyna.actor.world.pos, 30.0f, 30, 10.0f, 100, 30, true);
        this->inactive = true;
        this->timer = 50;
        this->actionFunc = EnEgblock_Inactive;
    }
}
