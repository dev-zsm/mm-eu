// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

void ObjKendoKanban_Init(Actor* thisx, PlayState* play) {
    s32 pad[2];
    ObjKendoKanban* this = (ObjKendoKanban*)thisx;
    Vec3f vertices[3];
    s32 i;
    s32 j;

    Actor_SetScale(&this->actor, 0.1f);

    Collider_InitCylinder(play, &this->colliderCylinder);
    Collider_SetCylinder(play, &this->colliderCylinder, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    Collider_InitTris(play, &this->colliderTris);
    Collider_SetTris(play, &this->colliderTris, &this->actor, &sTrisInit, this->colliderTrisElements);

    Matrix_SetTranslateRotateYXZ(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z,
                                 &this->actor.shape.rot);
    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);

    for (i = 0; i < ARRAY_COUNT(this->colliderTrisElements); i++) {
        for (j = 0; j < ARRAY_COUNT(vertices); j++) {
            Matrix_MultVec3f(&sTrisElementsInit[i].dim.vtx[j], &vertices[j]);
        }
        Collider_SetTrisVertices(&this->colliderTris, i, &vertices[0], &vertices[1], &vertices[2]);
    }

    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);

    this->boardFragments = OBJKENDOKANBAN_GET_BOARD_FRAGMENTS(&this->actor);
    this->actor.gravity = -2.0f;
    this->centerPoint = sZeroVec;
    this->centerPos = sZeroVec;
    this->rootCornerPos = sZeroVec;
    this->rotAxis = sUnitVecX;
    this->rotAngle = 0;
    this->angularVelocity = 0;
    this->indexLastRootCornerPos = -1;
    this->hasNewRootCornerPos = false;
    this->numBounces = 0;

    for (i = 0; i < ARRAY_COUNT(this->cornerPos); i++) {
        this->cornerPos[i] = this->cornerPoints[i] = sZeroVec;
    }

    this->unk_30A = 0;
    if (this->boardFragments == OBJKENDOKANBAN_PART_FULL) {
        ObjKendoKanban_SetupDoNothing(this);
    } else {
        ObjKendoKanban_SetupTumble(this, play);
    }
}
