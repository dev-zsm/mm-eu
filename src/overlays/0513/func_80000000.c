// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_mirror.h"

void BgIkanaMirror_SetQuadVertices(BgIkanaMirror* this) {
    ColliderQuadDimInit* dim;
    ColliderQuad* lightRaysCollider;
    Vec3f v0;
    Vec3f v1;
    Vec3f v2;
    Vec3f v3;
    s32 i;

    Matrix_Push();
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
    for (i = 0; i < ARRAY_COUNT(this->lightRaysColliders); i++) {
        dim = &sLightRaysCollidersInit[i].dim;
        Matrix_MultVec3f(&dim->quad[0], &v0);
        Matrix_MultVec3f(&dim->quad[1], &v1);
        Matrix_MultVec3f(&dim->quad[2], &v2);
        Matrix_MultVec3f(&dim->quad[3], &v3);
        lightRaysCollider = &this->lightRaysColliders[i];
        Collider_SetQuadVertices(lightRaysCollider, &v0, &v1, &v2, &v3);
    }

    Matrix_Pop();
}
