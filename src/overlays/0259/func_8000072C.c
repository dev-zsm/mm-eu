// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

void ObjGrass_UpdateGrass(ObjGrass* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    f32 distSq;
    ObjGrassGroup* grassGroup;
    s16 yaw;

    for (i = 0; i < OBJ_GRASS_NEAREST_ELEM_MAX; i++) {
        sNearestGrassElements[i] = NULL;
        sNearestGrassElementsDistSq[i] = SQ(650.0f);
    }

    for (i = 0; i < OBJ_GRASS_NEAREST_GROUP_MAX; i++) {
        sNearestGrassGroups[i] = NULL;
        sNearestGrassGroupsDist[i] = SQ(650.0f);
    }

    for (i = 0; i < this->activeGrassGroups; i++) {
        grassGroup = &this->grassGroups[i];

        for (j = 0; j < grassGroup->count; j++) {
            grassGroup->elements[j].flags &= (u16)~OBJ_GRASS_ELEM_ANIM;
        }
    }

    for (i = 0; i < this->activeGrassGroups; i++) {
        grassGroup = &this->grassGroups[i];
        distSq = Math3D_Vec3fDistSq(&grassGroup->homePos, &player->actor.world.pos);

        for (j = 0; j < OBJ_GRASS_NEAREST_GROUP_MAX; j++) {
            if (distSq < sNearestGrassGroupsDist[j]) {
                break;
            }
        }

        if (j < OBJ_GRASS_NEAREST_GROUP_MAX) {
            

            
            for (x = OBJ_GRASS_NEAREST_GROUP_MAX - 2; x >= j; x--) {
                sNearestGrassGroupsDist[x + 1] = sNearestGrassGroupsDist[x];
                sNearestGrassGroups[x + 1] = sNearestGrassGroups[x];
            }

            sNearestGrassGroupsDist[j] = distSq;
            sNearestGrassGroups[j] = grassGroup;
        }
    }

    this->carryGrassElem = NULL;

    for (i = 0; i < OBJ_GRASS_NEAREST_GROUP_MAX; i++) {
        grassGroup = sNearestGrassGroups[i];

        if (grassGroup != NULL) {
            for (j = 0; j < grassGroup->count; j++) {
                if (!(grassGroup->elements[j].flags & OBJ_GRASS_ELEM_REMOVED)) {
                    distSq = Math3D_Vec3fDistSq(&grassGroup->elements[j].pos, &player->actor.world.pos);

                    for (x = 0; x < OBJ_GRASS_NEAREST_ELEM_MAX; x++) {
                        if (distSq < sNearestGrassElementsDistSq[x]) {
                            break;
                        }
                    }

                    if (x < OBJ_GRASS_NEAREST_ELEM_MAX) {
                        

                        
                        for (y = OBJ_GRASS_NEAREST_ELEM_MAX - 2; y >= x; y--) {
                            sNearestGrassElementsDistSq[y + 1] = sNearestGrassElementsDistSq[y];
                            sNearestGrassElements[y + 1] = sNearestGrassElements[y];
                        }

                        sNearestGrassElementsDistSq[x] = distSq;
                        sNearestGrassElements[x] = &grassGroup->elements[j];

                        if (distSq < SQ(50.0f)) {
                            yaw = player->actor.shape.rot.y -
                                  Math_Vec3f_Yaw(&player->actor.world.pos, &grassGroup->elements[j].pos);

                            if (ABS_ALT(yaw) < 0x2000) {
                                this->carryGrassElem = &grassGroup->elements[j];
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->grassElemColliders); i++) {
        ObjGrassCollider* grassCol = &this->grassElemColliders[i];
        ObjGrassElement* grassElem;

        grassCol->collider.base.acFlags &= (u16)~AC_HIT;
        grassCol->collider.base.ocFlags1 &= (u16)~OC1_HIT;

        grassElem = sNearestGrassElements[i];
        if (grassElem != NULL) {
            grassCol->collider.dim.pos.x = grassElem->pos.x;
            grassCol->collider.dim.pos.y = grassElem->pos.y;
            grassCol->collider.dim.pos.z = grassElem->pos.z;
            CollisionCheck_SetAC(play, &play->colChkCtx, &grassCol->collider.base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &grassCol->collider.base);
            grassElem->flags |= OBJ_GRASS_ELEM_ANIM;
            grassCol->entity = grassElem;
        } else {
            grassCol->entity = NULL;
        }
    }
}
