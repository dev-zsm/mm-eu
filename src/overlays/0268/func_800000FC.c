// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarpTag_CheckDungeonKeepObject(EnWarptag* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->dangeonKeepObjectSlot)) {
        this->actionFunc = EnWarpTag_WaitForPlayer;
        DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWarpTagGoronTrialBaseCol);
        this->dyna.actor.objectSlot = this->dangeonKeepObjectSlot;
        this->dyna.actor.draw = EnWarpTag_Draw;
    }
}
