// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

void EnBomChu_HandleNonSceneCollision(EnBomChu* this, PlayState* play) {
    Vec3f originalWorldPos;
    Vec3f posA;
    Vec3f posB;
    Vec3f originalAxisUp;
    s16 yaw;
    f32 sin;
    f32 cos;
    f32 tempX;
    CollisionPoly* poly = NULL;
    s32 bgId = BGCHECK_SCENE;
    s32 isFloorPolyValid;

    Math_Vec3f_Copy(&originalWorldPos, &this->actor.world.pos);
    Math_Vec3f_Copy(&originalAxisUp, &this->axisUp);
    yaw = this->actor.shape.rot.y;
    DynaPolyActor_TransformCarriedActor(&play->colCtx, this->actor.floorBgId, &this->actor);

    if (yaw != this->actor.shape.rot.y) {
        yaw = this->actor.shape.rot.y - yaw;

        sin = Math_SinS(yaw);
        cos = Math_CosS(yaw);

        tempX = this->axisForwards.x;
        this->axisForwards.x = (sin * this->axisForwards.z) + (cos * tempX);
        this->axisForwards.z = (cos * this->axisForwards.z) - (sin * tempX);

        tempX = this->axisUp.x;
        this->axisUp.x = (sin * this->axisUp.z) + (cos * tempX);
        this->axisUp.z = (cos * this->axisUp.z) - (sin * tempX);

        tempX = this->axisLeft.x;
        this->axisLeft.x = (sin * this->axisLeft.z) + (cos * tempX);
        this->axisLeft.z = (cos * this->axisLeft.z) - (sin * tempX);
    }

    posA.x = originalWorldPos.x + (2.0f * originalAxisUp.x);
    posA.y = originalWorldPos.y + (2.0f * originalAxisUp.y);
    posA.z = originalWorldPos.z + (2.0f * originalAxisUp.z);

    posB.x = this->actor.world.pos.x + (2.0f * this->axisUp.x);
    posB.y = this->actor.world.pos.y + (2.0f * this->axisUp.y);
    posB.z = this->actor.world.pos.z + (2.0f * this->axisUp.z);

    if (EnBomChu_IsOnCollisionPoly(play, &posA, &posB, &originalWorldPos, &poly, &bgId)) {
        isFloorPolyValid = EnBomChu_UpdateFloorPoly(this, poly, play);
        Math_Vec3f_Copy(&this->actor.world.pos, &originalWorldPos);
        this->actor.floorBgId = bgId;
        this->actor.speed = 0.0f;

        if (isFloorPolyValid) {
            EnBomChu_UpdateRotation(this);
            this->actor.shape.rot.x = -this->actor.world.rot.x;
            this->actor.shape.rot.y = this->actor.world.rot.y;
            this->actor.shape.rot.z = this->actor.world.rot.z;
        }
    }
}
