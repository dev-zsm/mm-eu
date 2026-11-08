// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_sbn.h"

u32 EffectSsSbn_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsSbnInitParams* initParams = PARAMS;
    CollisionPoly* colPoly;
    MtxF mtx;
    Vec3f normal;
    Vec3f colPolyVec;
    Vec3f bubbleVec;
    f32 angle;
    f32 opposite;

    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    Math_Vec3f_Copy(&this->velocity, &gZeroVec3f);
    Math_Vec3f_Copy(&this->accel, &gZeroVec3f);
    this->flags = 0;

    this->gfx = initParams->colPoly;

    this->rScroll = 0;
    this->rScrollStep = 7;
    this->rTexIndex = 0;
    this->rAlpha = 200;
    this->rReg4 = 250;
    this->rReg4Step = 30;

    this->rScale = Rand_CenteredFloat(100.0f) + (initParams->scale * 120.0f);
    if (this->rScale < 600) {
        this->rScale = 600;
    } else if (this->rScale > 1500) {
        this->rScale = 1500;
    }

    this->rReg8 = 1000;
    this->rRotAngle = 0;
    this->life = 93;
    this->draw = EffectSsSbn_DrawSliding;
    this->update = EffectSsSbn_Update;

    if (this->gfx != NULL) {
        colPoly = this->gfx;
        ref_func_800C0094(colPoly, this->pos.x, this->pos.y, this->pos.z, &mtx);
        normal.x = COLPOLY_GET_NORMAL(colPoly->normal.x);
        normal.y = COLPOLY_GET_NORMAL(colPoly->normal.y);
        normal.z = COLPOLY_GET_NORMAL(colPoly->normal.z);
        if ((normal.y > 0.95f) || (normal.y < -0.95f)) {
            this->draw = EffectSsSbn_Draw;
            return 1;
        }
        if (normal.y > 0.05f) {
            colPolyVec.x = normal.x * 10.0f;
            colPolyVec.y = (-(SQ(normal.x) + SQ(normal.z)) * 10.0f) / normal.y;
            colPolyVec.z = normal.z * 10.0f;
        } else if (normal.y < -0.05f) {
            colPolyVec.x = -normal.x * 10.0f;
            colPolyVec.y = (-(SQ(normal.x) + SQ(normal.z)) * 10.0f) / -normal.y;
            colPolyVec.z = -normal.z * 10.0f;
        } else {
            colPolyVec.x = 0.0f;
            colPolyVec.y = -10.0f;
            colPolyVec.z = 0.0f;
        }
        bubbleVec.x = -mtx.mf[2][0] * 10.0f;
        bubbleVec.y = -mtx.mf[2][1] * 10.0f;
        bubbleVec.z = -mtx.mf[2][2] * 10.0f;
        Math3D_CosOut(&colPolyVec, &bubbleVec, &angle);

        opposite = (SQ(angle) >= 1.0f) ? 0.0f : sqrtf(1.0f - SQ(angle));
        if (((mtx.mf[0][0] * colPolyVec.x) + (mtx.mf[0][1] * colPolyVec.y) + (mtx.mf[0][2] * colPolyVec.z)) < 0.0f) {
            this->rRotAngle = Math_Atan2S_XY(angle, opposite);
        } else {
            this->rRotAngle = -Math_Atan2S_XY(angle, opposite);
        }
    }

    return 1;
}
