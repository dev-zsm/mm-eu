// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mm.h"

void ref_func_80965DB4(EnMm* this, PlayState* play) {
    s16 direction;
    Vec3f slopeNormal;
    s16 downwardSlopeYaw;
    f32 temp_f14;
    f32 temp_f12;
    f32 temp_f2;
    s32 angle;
    s32 pad;

    if (Actor_HasParent(&this->actor, play)) {
        ref_func_80965BBC(this);
        Actor_PlaySfx(&this->actor, NA_SE_PL_PULL_UP_ROCK);
    } else {
        if ((this->actor.velocity.y > 0.0f) && (this->actor.bgCheckFlags & BGCHECKFLAG_CEILING)) {
            this->actor.velocity.y = 0.0f;
        }

        if ((this->actor.speed != 0.0f) && (this->actor.bgCheckFlags & BGCHECKFLAG_WALL)) {
            angle = BINANG_SUB(this->actor.world.rot.y, BINANG_ROT180(this->actor.wallYaw));
            this->actor.world.rot.y += BINANG_SUB(0x8000, (s16)(angle * 2));
            this->actor.speed *= 0.5f;
            CollisionCheck_SpawnShieldParticles(play, &this->actor.world.pos);
            Actor_PlaySfx(&this->actor, NA_SE_EV_HUMAN_BOUND);
        }

        if (!(this->actor.bgCheckFlags & BGCHECKFLAG_GROUND)) {
            Math_StepToF(&this->actor.speed, 0.0f, 0.08f);
        } else {
            temp_f14 = Math_SinS(this->actor.world.rot.y) * this->actor.speed;
            temp_f12 = Math_CosS(this->actor.world.rot.y) * this->actor.speed;
            Actor_GetSlopeDirection(this->actor.floorPoly, &slopeNormal, &downwardSlopeYaw);
            temp_f14 += 3.0f * slopeNormal.x;
            temp_f12 += 3.0f * slopeNormal.z;
            temp_f2 = sqrtf(SQ(temp_f14) + SQ(temp_f12));

            if ((temp_f2 < this->actor.speed) ||
                (SurfaceType_GetFloorEffect(&play->colCtx, this->actor.floorPoly, this->actor.floorBgId) ==
                 FLOOR_EFFECT_1)) {
                this->actor.speed = CLAMP_MAX(temp_f2, 16.0f);
                this->actor.world.rot.y = Math_Atan2S_XY(temp_f12, temp_f14);
            }

            if (!Math_StepToF(&this->actor.speed, 0.0f, 1.0f)) {
                direction = this->actor.world.rot.y;
                if (ABS_ALT(BINANG_SUB(this->actor.world.rot.y, this->actor.shape.rot.y)) > 0x4000) {
                    direction = BINANG_ROT180(direction);
                }
                Math_ScaledStepToS(&this->actor.shape.rot.y, direction, this->actor.speed * 100.0f);
                this->unk_190 += TRUNCF_BINANG(this->actor.speed * 800.0f);
            }

            if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
                if (this->actor.velocity.y < -6.0f) {
                    this->actor.velocity.y *= -0.3f;
                    this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
                }

                Actor_PlaySfx(&this->actor, NA_SE_EV_HUMAN_BOUND);
            } else {
                Actor_OfferGetItem(&this->actor, play, GI_NONE, 50.0f, 30.0f);
            }
        }

        Actor_MoveWithGravity(&this->actor);
    }

    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
