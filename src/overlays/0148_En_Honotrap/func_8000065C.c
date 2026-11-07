// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_Destroy(Actor* thisx, PlayState* play) {
    s16 params;
    EnHonotrap* this = (EnHonotrap*)thisx;

    params = this->actor.params;
    if ((params == HONOTRAP_TYPE_EYE) || (params == HONOTRAP_TYPE_EYE_MUTI_FLAME)) {
        Collider_DestroyTris(play, &this->collider.tris);
    } else {
        Collider_DestroyCylinder(play, &this->collider.cyl);
    }
}
