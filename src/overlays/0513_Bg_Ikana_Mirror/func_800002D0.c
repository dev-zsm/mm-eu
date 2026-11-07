// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_mirror.h"

void BgIkanaMirror_Destroy(Actor* thisx, PlayState* play) {
    BgIkanaMirror* this = (BgIkanaMirror*)thisx;
    s32 i;

    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
    Collider_DestroyTris(play, &this->mirrorCollider);

    for (i = 0; i < ARRAY_COUNT(this->lightRaysColliders); i++) {
        Collider_DestroyQuad(play, &this->lightRaysColliders[i]);
    }
}
