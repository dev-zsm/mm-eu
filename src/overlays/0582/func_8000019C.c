// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hsstump.h"

void ObjHsStump_Appear(ObjHsStump* this, PlayState* play) {
    if (this->framesAppeared >= 0) {
        Math_SmoothStepToF(&this->rotFactor, 0.0f, 1.0f, this->framesAppeared + 18.0f, 0.01f);
        this->dyna.actor.shape.rot.x = (Math_SinS(this->rotAngle) * this->rotFactor) + this->dyna.actor.home.rot.x;
        this->dyna.actor.shape.rot.z = (Math_SinS(this->rotAngle * 2) * this->rotFactor) + this->dyna.actor.home.rot.z;
        this->rotAngle += 0x2000;
    }
    if (this->framesAppeared <= 10) {
        if (this->framesAppeared == 0) {
            s32 pad;
            s32 i;
            s16 numDirections = 4;
            Vec3f iceSmokePosOffset;
            Vec3f iceSmokeVelOffset;
            s16 iceSmokeAngle;
            Vec3f iceSmokeVel;
            f32 baseAngle;
            Vec3f iceSmokePos;

            iceSmokePosOffset.x = 1.0f;
            iceSmokePosOffset.y = 0.5f;
            iceSmokePosOffset.z = 0.0f;

            iceSmokeVelOffset.x = 1.0f;
            iceSmokeVelOffset.y = 0.5f;
            iceSmokeVelOffset.z = 0.0f;

            baseAngle = (s32)DEG_TO_BINANG_ALT3(360.0f / numDirections);

            for (i = 0; i < numDirections; i++) {
                iceSmokeAngle = i * baseAngle;
                Lib_Vec3f_TranslateAndRotateY(&this->dyna.actor.world.pos, iceSmokeAngle, &iceSmokePosOffset,
                                              &iceSmokePos);
                Lib_Vec3f_TranslateAndRotateY(&gZeroVec3f, iceSmokeAngle, &iceSmokeVelOffset, &iceSmokeVel);
                EffectSsIceSmoke_Spawn(play, &iceSmokePos, &iceSmokeVel, &sIceSmokeAccel, 100);
            }
        }
    }
    if (this->framesAppeared >= 10) {
        Math_SmoothStepToF(&this->dyna.actor.scale.x, 18.0f * 0.01f, 1.0f, 0.01f, 0.001f);
        Actor_SetScale(&this->dyna.actor, this->dyna.actor.scale.x);
    }
    if (this->dyna.actor.scale.x == (18.0f * 0.01f)) {
        this->isHidden = false;
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        ObjHsStump_SetupIdle(this, play);
    }
    this->framesAppeared++;
}
