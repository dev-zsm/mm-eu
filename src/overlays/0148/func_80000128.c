// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_InitEye(EnHonotrap* this, PlayState* play) {
    s32 i;
    s32 j;
    s32 k;
    f32 sin = Math_SinS(this->actor.home.rot.y);
    f32 cos = Math_CosS(this->actor.home.rot.y);
    Vec3f triangle[3];
    Vec3f* vtx;

    Actor_SetScale(&this->actor, 0.1f);

    if (sTexturesNotDesegmented) {
        sTexturesNotDesegmented = false;
        for (k = 0; k < HONOTRAP_EYE_MAX; k++) {
            sSilverEyeTextures[k] = Lib_SegmentedToVirtual(sSilverEyeTextures[k]);
        }
    }

    Collider_InitTris(play, &this->collider.tris);
    Collider_SetTris(play, &this->collider.tris, &this->actor, &sTrisInit, this->collider.elements);

    for (i = 0; i < 2; i++) {
        for (j = 0, vtx = triangle; j < 3; j++, vtx++) {
            Vec3f* baseVtx = &sTrisInit.elements[i].dim.vtx[j];

            vtx->x = (baseVtx->z * sin) + (baseVtx->x * cos);
            vtx->y = baseVtx->y;
            vtx->z = (baseVtx->z * cos) - (baseVtx->x * sin);

            Math_Vec3f_Sum(vtx, &this->actor.world.pos, vtx);
        }
        Collider_SetTrisVertices(&this->collider.tris, i, &triangle[0], &triangle[1], &triangle[2]);
    }
    Actor_SetFocus(&this->actor, 0.0f);
    if (this->actor.params == HONOTRAP_TYPE_EYE) {
        EnHonotrap_SetupEyeIdle(this);
    } else { 
        EnHonotrap_SetupEyeIdle2(this);
    }
}
