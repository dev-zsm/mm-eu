// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void ref_func_809CE068(BgSpdweb* this) {
    Vec3f sp64[3];
    s32 i;
    s32 j;

    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    for (i = 0; i < this->collider.count; i++) {
        for (j = 0; j < ARRAY_COUNT(sp64); j++) {
            Matrix_MultVec3f(this->collider.elements[i].dim.vtx + j, &sp64[j]);
        }
        Collider_SetTrisVertices(&this->collider, i, &sp64[0], &sp64[1], &sp64[2]);
    }
}
