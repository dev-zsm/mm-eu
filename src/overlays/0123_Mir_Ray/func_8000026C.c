// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    MirRay* this = (MirRay*)thisx;
    MirRayDataEntry* dataEntry = &sMirRayData[MIRRAY_LOCATION(&this->actor)];

    Actor_ProcessInitChain(&this->actor, sInitChain);
    ActorShape_Init(&this->actor.shape, 0.0f, NULL, 0.0f);

    if (MIRRAY_LOCATION(&this->actor) >= MIRRAY_MAX) {
        (void)T("反射光 発生失敗", "Reflected light failed to spawn");
        Actor_Kill(&this->actor);
    }

    this->sourcePt.x = dataEntry->sourcePoint.x;
    this->sourcePt.y = dataEntry->sourcePoint.y;
    this->sourcePt.z = dataEntry->sourcePoint.z;
    this->sourceEndRad = dataEntry->sourceEndRadius;

    this->poolPt.x = dataEntry->poolPoint.x;
    this->poolPt.y = dataEntry->poolPoint.y;
    this->poolPt.z = dataEntry->poolPoint.z;
    this->poolEndRad = dataEntry->poolEndRadius;

    Lights_PointNoGlowSetInfo(&this->lightInfo, this->sourcePt.x, this->sourcePt.y, this->sourcePt.z, 255, 255, 255,
                              100);
    this->lightNode = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);

    this->shieldCorners[0].x = -536.0f;
    this->shieldCorners[0].y = -939.0f;

    this->shieldCorners[1].x = -1690.0f;
    this->shieldCorners[1].y = 0.0f;

    this->shieldCorners[2].x = -536.0f;
    this->shieldCorners[2].y = 938.0f;

    this->shieldCorners[3].x = 921.0f;
    this->shieldCorners[3].y = 0.0f;

    this->shieldCorners[4].x = 758.0f;
    this->shieldCorners[4].y = 800.0f;

    this->shieldCorners[5].x = 758.0f;
    this->shieldCorners[5].y = -800.0f;

    if (dataEntry->params & 2) {
        Collider_InitJntSph(play, &this->collider1);
        Collider_SetJntSph(play, &this->collider1, &this->actor, &sJntSphInit, this->collider1Elements);
        if (!(dataEntry->params & 4)) { 
            MirRay_SetupCollider(this);
        }
    }

    Collider_InitQuad(play, &this->collider2);
    Collider_SetQuad(play, &this->collider2, &this->actor, &sQuadInit);

    if ((MIRRAY_LOCATION(&this->actor) == MIRRAY_SPIRIT_TOPROOM_CEILINGMIRROR) ||
        (MIRRAY_LOCATION(&this->actor) == MIRRAY_SPIRIT_TOPROOM_COBRA1) ||
        (MIRRAY_LOCATION(&this->actor) == MIRRAY_SPIRIT_TOPROOM_COBRA2)) {
        this->actor.room = -1;
    }
}
