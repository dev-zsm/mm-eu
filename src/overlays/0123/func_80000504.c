// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_Destroy(Actor* thisx, PlayState* play) {
    MirRay* this = (MirRay*)thisx;

    LightContext_RemoveLight(play, &play->lightCtx, this->lightNode);

    if (sMirRayData[MIRRAY_LOCATION(&this->actor)].params & 2) {
        Collider_DestroyJntSph(play, &this->collider1);
    }

    Collider_DestroyQuad(play, &this->collider2);
}
