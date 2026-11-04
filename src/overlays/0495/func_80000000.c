// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dora.h"

void ObjDora_Init(Actor* thisx, PlayState* play) {
    ObjDora* this = (ObjDora*)thisx;
    s32 i;
    s32 j;
    Vec3f vtx[3];
    s32 buf = 0;
    s32 buff2 = 0;

    Actor_SetScale(&this->actor, 0.1f);
    ActorShape_Init(&this->actor.shape, 0.0f, &ActorShadow_DrawCircle, 36.0f);

    this->gongRotation.x = 0;
    this->gongRotation.z = 0;
    this->gongAngle.x = 0;
    this->gongAngle.z = 0;
    this->lastGongHitType = DORA_HIT_NONE;
    this->rupeeDropTimer = 0;
    this->collisionCooldownTimer = 0;
    this->unk3AA = 0;
    this->gongForce.x = 0.0f;
    this->gongForce.y = 0.0f;
    this->gongForce.z = 0.0f;

    Collider_InitTris(play, &this->colliderTris);
    Collider_SetTris(play, &this->colliderTris, &this->actor, &sTrisInit, this->colliderTrisElements);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);

    Matrix_SetTranslateRotateYXZ(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z,
                                 &this->actor.shape.rot);
    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);

    for (i = 0; i < ARRAY_COUNT(this->colliderTrisElements); i++) {
        for (j = 0; j < ARRAY_COUNT(vtx); j++) {
            Matrix_MultVec3f(&sTrisElementsInit[i].dim.vtx[j], &vtx[j]);
        }
        Collider_SetTrisVertices(&this->colliderTris, i, &vtx[0], &vtx[1], &vtx[2]);
    }
    ObjDora_SetupWait(this);
}
