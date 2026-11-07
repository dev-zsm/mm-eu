// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

void EnBomChu_Move(EnBomChu* this, PlayState* play) {
    CollisionPoly* polySide = NULL;
    CollisionPoly* polyUpDown = NULL;
    s32 bgIdSide;
    s32 bgIdUpDown;
    s32 i;
    s32 isFloorPolyValid;
    f32 lineLength;
    Vec3f posA;
    Vec3f posB;
    Vec3f posSide;
    Vec3f posUpDown;

    bgIdUpDown = bgIdSide = BGCHECK_SCENE;
    isFloorPolyValid = false;

    this->actor.speed = this->movingSpeed;
    lineLength = 2.0f * this->movingSpeed;

    if ((this->timer == 0) || (this->collider.base.acFlags & AC_HIT) || (this->collider.base.ocFlags1 & OC1_HIT)) {
        EnBomChu_Explode(this, play);
        return;
    }

    posA.x = this->actor.world.pos.x + (this->axisUp.x * 2.0f);
    posA.y = this->actor.world.pos.y + (this->axisUp.y * 2.0f);
    posA.z = this->actor.world.pos.z + (this->axisUp.z * 2.0f);

    posB.x = this->actor.world.pos.x - (this->axisUp.x * 4.0f);
    posB.y = this->actor.world.pos.y - (this->axisUp.y * 4.0f);
    posB.z = this->actor.world.pos.z - (this->axisUp.z * 4.0f);

    if (EnBomChu_IsOnCollisionPoly(play, &posA, &posB, &posUpDown, &polyUpDown, &bgIdUpDown)) {
        
        posB.x = (this->axisForwards.x * lineLength) + posA.x;
        posB.y = (this->axisForwards.y * lineLength) + posA.y;
        posB.z = (this->axisForwards.z * lineLength) + posA.z;

        if (EnBomChu_IsOnCollisionPoly(play, &posA, &posB, &posSide, &polySide, &bgIdSide)) {
            isFloorPolyValid = EnBomChu_UpdateFloorPoly(this, polySide, play);
            Math_Vec3f_Copy(&this->actor.world.pos, &posSide);
            this->actor.floorBgId = bgIdSide;
            this->actor.speed = 0.0f;
        } else {
            if (this->actor.floorPoly != polyUpDown) {
                isFloorPolyValid = EnBomChu_UpdateFloorPoly(this, polyUpDown, play);
            }

            Math_Vec3f_Copy(&this->actor.world.pos, &posUpDown);
            this->actor.floorBgId = bgIdUpDown;
        }
    } else {
        this->actor.speed = 0.0f;
        lineLength *= 3.0f;
        Math_Vec3f_Copy(&posA, &posB);

        for (i = 0; i < 3; i++) {
            if (i == 0) {
                
                posB.x = posA.x - (this->axisForwards.x * lineLength);
                posB.y = posA.y - (this->axisForwards.y * lineLength);
                posB.z = posA.z - (this->axisForwards.z * lineLength);
            } else if (i == 1) {
                
                posB.x = posA.x + (this->axisLeft.x * lineLength);
                posB.y = posA.y + (this->axisLeft.y * lineLength);
                posB.z = posA.z + (this->axisLeft.z * lineLength);
            } else {
                
                posB.x = posA.x - (this->axisLeft.x * lineLength);
                posB.y = posA.y - (this->axisLeft.y * lineLength);
                posB.z = posA.z - (this->axisLeft.z * lineLength);
            }

            if (EnBomChu_IsOnCollisionPoly(play, &posA, &posB, &posSide, &polySide, &bgIdSide)) {
                isFloorPolyValid = EnBomChu_UpdateFloorPoly(this, polySide, play);
                Math_Vec3f_Copy(&this->actor.world.pos, &posSide);
                this->actor.floorBgId = bgIdSide;
                break;
            }
        }

        if (i == 3) {
            
            EnBomChu_Explode(this, play);
        }
    }

    if (isFloorPolyValid) {
        EnBomChu_UpdateRotation(this);
        this->actor.shape.rot.x = -this->actor.world.rot.x;
        this->actor.shape.rot.y = this->actor.world.rot.y;
        this->actor.shape.rot.z = this->actor.world.rot.z;
    }

    if (this->isMoving) {
        Actor_PlaySfx_Flagged2(&this->actor, NA_SE_IT_BOMBCHU_MOVE - SFX_FLAG);
    }

    if (this->actor.speed != 0.0f) {
        this->movingSpeed = this->actor.speed;
    }
}
