// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

void ObjGrass_InitDraw(ObjGrass* this, PlayState* play) {
    ObjGrassGroup* grassGroup;
    ObjGrassElement* grassElem;
    s32 i;
    s32 j;
    f32 distSq;
    f32 eyeDist;

    for (i = 0; i < this->activeGrassGroups; i++) {
        grassGroup = &this->grassGroups[i];

        eyeDist = Math3D_Vec3fDistSq(&grassGroup->homePos, &GET_ACTIVE_CAM(play)->eye);

        if ((eyeDist < SQ(1280.0f)) && ref_func_809A9110(play, &grassGroup->homePos)) {
            grassGroup->flags |= OBJ_GRASS_GROUP_DRAW;

            for (j = 0; j < grassGroup->count; j++) {
                grassElem = &grassGroup->elements[j];

                if (grassElem->flags & OBJ_GRASS_ELEM_REMOVED) {
                    grassElem->alpha = 255;
                    grassElem->flags &= ~OBJ_GRASS_ELEM_DRAW;
                } else {
                    grassElem->flags |= OBJ_GRASS_ELEM_DRAW;
                    if (eyeDist < SQ(980.0f)) {
                        grassElem->alpha = 255;
                    } else {
                        distSq = Math3D_Vec3fDistSq(&grassElem->pos, &GET_ACTIVE_CAM(play)->eye);
                        if ((distSq <= SQ(1080.0f)) ||
                            ((grassElem->flags & OBJ_GRASS_ELEM_UNDERWATER) && (distSq < SQ(1180.0f)))) {
                            grassElem->alpha = 255;
                        } else if (distSq >= SQ(1180.0f)) {
                            grassElem->alpha = 0;
                        } else {
                            grassElem->alpha = (1180.0f - sqrtf(distSq)) * 2.55f;
                        }
                    }
                }
            }
        } else {
            grassGroup->flags &= ~OBJ_GRASS_GROUP_DRAW;
        }
    }
}
