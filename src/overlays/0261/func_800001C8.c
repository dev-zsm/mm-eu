// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_unit.h"

void ObjGrassUnit_Init(Actor* this, PlayState* play2) {
    PlayState* play = play2;
    ObjGrassGroup* grassGroup;
    ObjGrass* grassManager;
    f32 homePosYSum;
    f32 tmp;
    s32 i;
    VecPolar* grassPos;
    CollisionPoly* poly;
    s32 bgId;
    ObjGrassElement* grassElem;
    ObjGrassUnitPattern* grassPattern;
    s8 dropTable = OBJGRASSUNIT_GET_DROPTABLE(this);

    if ((sGrassManager == NULL) && !ObjGrassUnit_SpawnObjGrass(this, play)) {
        Actor_Kill(this);
        return;
    }
    if ((sGrassCarry0 == NULL) && ObjGrassUnit_SpawnObjGrassCarry0(this, play)) {
        sGrassCarry0->grassManager = sGrassManager;
    }
    if ((sGrassCarry1 == NULL) && ObjGrassUnit_SpawnObjGrassCarry1(this, play)) {
        sGrassCarry1->grassManager = sGrassManager;
    }
    if (!sInitialized && (sGrassManager != NULL) && (sGrassCarry0 != NULL) && (sGrassCarry1 != NULL)) {
        sInitialized = true;
        sGrassManager->grassCarry[0] = sGrassCarry0;
        sGrassManager->grassCarry[1] = sGrassCarry1;
        sGrassCarry0->grassManager = sGrassManager;
        sGrassCarry1->grassManager = sGrassManager;
    }

    grassManager = sGrassManager;
    if (sGrassManager->activeGrassGroups >= ARRAY_COUNT(sGrassManager->grassGroups)) {
        Actor_Kill(this);
        return;
    }

    homePosYSum = 0.0f;
    grassGroup = &grassManager->grassGroups[sGrassManager->activeGrassGroups];
    grassGroup->count = 0;
    grassPattern = &sGrassPatterns[OBJGRASSUNIT_GET_PATTERN(this)];

    for (i = 0; i < grassPattern->count; i++) {
        grassElem = &grassGroup->elements[grassGroup->count];
        grassPos = &grassPattern->positions[i];

        grassElem->pos.x = this->home.pos.x + (Math_CosS(this->home.rot.y + grassPos->angle) * grassPos->distance);
        grassElem->pos.y = this->home.pos.y + 100.0f;
        grassElem->pos.z = this->home.pos.z + (Math_SinS(this->home.rot.y + grassPos->angle) * grassPos->distance);

        grassElem->pos.y = BgCheck_EntityRaycastFloor5(&play->colCtx, &poly, &bgId, this, &grassElem->pos);
        tmp = grassElem->pos.y - this->home.pos.y;
        if ((fabsf(tmp) < 80.0f) && (grassElem->pos.y > BGCHECK_Y_MIN)) {
            grassGroup->count++;
            grassElem->rotY = (s16)(Rand_Next() >> 0x10);
            grassElem->dropTable = dropTable;
            if (ObjGrassUnit_IsUnderwater(play, &grassElem->pos)) {
                grassElem->flags |= OBJ_GRASS_ELEM_UNDERWATER;
            }
            homePosYSum += grassElem->pos.y;
        }
    }
    if (grassGroup->count > 0) {
        grassManager->activeGrassGroups++;
        grassGroup->homePos.x = this->home.pos.x;
        grassGroup->homePos.y = (homePosYSum / grassGroup->count);
        grassGroup->homePos.z = this->home.pos.z;
    }
    Actor_Kill(this);
}
