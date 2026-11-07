// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_Move(EnBom* this, PlayState* play) {
    static Vec3f ref_D_80872E68[] = {
        { 2.0f, -6.0f, -0.3f },
        { 1.5f, -5.0f, -0.6f },
        { 0.2f, -6.0f, -0.1f },
    };

    
    if (Actor_HasParent(&this->actor, play)) {
        this->actionFunc = EnBom_WaitForRelease;
        this->actor.room = -1;
        return;
    }

    if ((this->actor.velocity.y > 0.0f) && (this->actor.bgCheckFlags & BGCHECKFLAG_CEILING)) {
        this->actor.velocity.y = -this->actor.velocity.y;
    }

    
    if ((this->actor.speed != 0.0f) && (this->actor.bgCheckFlags & BGCHECKFLAG_WALL)) {
        s16 yDiff = BINANG_SUB(this->actor.wallYaw, this->actor.world.rot.y);

        if (ABS_ALT(yDiff) > 0x4000) {
            this->actor.world.rot.y =
                BINANG_SUB(this->actor.wallYaw - this->actor.world.rot.y + this->actor.wallYaw, 0x8000);
        }

        Actor_PlaySfx(&this->actor, this->isPowderKeg ? NA_SE_EV_PUT_DOWN_WOODBOX : NA_SE_EV_BOMB_BOUND);
        Actor_MoveWithGravity(&this->actor);
        this->actor.speed *= 0.7f;
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_WALL;
    }

    if (!(this->actor.bgCheckFlags & BGCHECKFLAG_GROUND)) {
        Math_StepToF(&this->actor.speed, 0.0f, 0.08f);
    } else {
        Vec3f* sp58;
        FloorType floorType = SurfaceType_GetFloorType(&play->colCtx, this->actor.floorPoly, this->actor.floorBgId);
        Vec3f slopeNormal;
        s16 downwardSlopeYaw;
        f32 sp40;
        f32 sp3C;
        f32 sp38;

        sp58 = &ref_D_80872E68[this->isPowderKeg];

        if (floorType == FLOOR_TYPE_5) {
            sp58 = &ref_D_80872E68[2];
        }

        if ((floorType == FLOOR_TYPE_4) || (floorType == FLOOR_TYPE_14) || (floorType == FLOOR_TYPE_15)) {
            s16 sp36;

            Math_ApproachF(&this->actor.shape.yOffset, 0.0f, 0.1f, 50.0f);
            sp36 = this->actor.shape.shadowAlpha;
            Math_ApproachS(&sp36, 0, 1, 20);
            this->actor.shape.shadowAlpha = sp36;
        } else {
            Math_ApproachF(&this->actor.shape.yOffset, 700.0f, 1.0f, 700.0f);
        }

        sp40 = Math_SinS(this->actor.world.rot.y) * this->actor.speed;
        sp3C = Math_CosS(this->actor.world.rot.y) * this->actor.speed;
        Actor_GetSlopeDirection(this->actor.floorPoly, &slopeNormal, &downwardSlopeYaw);

        sp40 += 3.0f * slopeNormal.x;
        sp3C += 3.0f * slopeNormal.z;
        sp38 = sqrtf(SQ(sp40) + SQ(sp3C));

        if ((sp38 < this->actor.speed) || (SurfaceType_GetFloorEffect(&play->colCtx, this->actor.floorPoly,
                                                                      this->actor.floorBgId) == FLOOR_EFFECT_1)) {
            if (sp38 > 16.0f) {
                this->actor.speed = 16.0f;
            } else {
                this->actor.speed = sp38;
            }
            this->actor.world.rot.y = Math_Atan2S_XY(sp3C, sp40);
        }

        if (!Math_StepToF(&this->actor.speed, 0.0f, sp58->x)) {
            s16 temp = this->actor.world.rot.y;
            s32 pad;

            if (ABS_ALT(BINANG_SUB(this->actor.world.rot.y, this->actor.shape.rot.y)) > 0x4000) {
                temp = BINANG_ROT180(temp);
            }
            Math_ScaledStepToS(&this->actor.shape.rot.y, temp, this->actor.speed * 100.0f);
            this->unk_1FA += TRUNCF_BINANG(this->actor.speed * 800.0f);
        }

        if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
            Actor_PlaySfx(&this->actor, this->isPowderKeg ? NA_SE_EV_TRE_BOX_BOUND : NA_SE_EV_BOMB_BOUND);
            if (this->actor.velocity.y < sp58->y) {
                if ((floorType == FLOOR_TYPE_4) || (floorType == FLOOR_TYPE_14) || (floorType == FLOOR_TYPE_15)) {
                    this->actor.velocity.y = 0.0f;
                } else {
                    this->actor.velocity.y *= sp58->z;
                }
                this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
            }
        } else if (this->timer >= 4) {
            Actor_OfferCarry(&this->actor, play);
        }
    }

    Actor_MoveWithGravity(&this->actor);
}
