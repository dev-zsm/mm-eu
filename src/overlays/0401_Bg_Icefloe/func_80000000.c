// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icefloe.h"

void BgIcefloe_Init(Actor* thisx, PlayState* play) {
    BgIcefloe* this = (BgIcefloe*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gIcefloePlatformCol);
    if (numberSpawned >= ARRAY_COUNT(sSpawnedInstances)) {
        s32 i;

        if ((sSpawnedInstances[0] != NULL) && (sSpawnedInstances[0]->dyna.actor.update != NULL) &&
            (sSpawnedInstances[0]->actionFunc != ref_func_80AC4D2C)) {
            ref_func_80AC4CF0(sSpawnedInstances[0]);
        }
        for (i = 0; i < ARRAY_COUNT(sSpawnedInstances) - 1; i++) {
            sSpawnedInstances[i] = sSpawnedInstances[i + 1];
        }
        sSpawnedInstances[ARRAY_COUNT(sSpawnedInstances) - 1] = this;
    } else {
        sSpawnedInstances[numberSpawned] = this;
    }
    numberSpawned++;
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 10.0f;
    ref_func_80AC4A80(this, play);
}
