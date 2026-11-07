// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_Init(Actor* thisx, PlayState* play) {
    s32 pad[3];
    EnClearTag* this = (EnClearTag*)thisx;
    f32 lightRayMaxScale;
    u8 i;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;

    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    if (thisx->params >= 0) {
        this->activeTimer = 70;
        Math_Vec3f_Copy(&pos, &this->actor.world.pos);

        
        if (thisx->params == CLEAR_TAG_SMOKE) {
            EnClearTag_CreateIsolatedSmokeEffect(this, &pos, this->actor.world.rot.z);
            return;
        }

        if (thisx->params != CLEAR_TAG_SPLASH) {
            
            if ((thisx->params == CLEAR_TAG_SMALL_LIGHT_RAYS) || (thisx->params == CLEAR_TAG_LARGE_LIGHT_RAYS)) {
                for (i = 0; i < 54; i++) {
                    lightRayMaxScale =
                        sLightRayMaxScale[thisx->params] + Rand_ZeroFloat(sLightRayMaxScale[thisx->params]);
                    Matrix_RotateYF(Rand_ZeroFloat(M_PIf * 2), MTXMODE_NEW);
                    Matrix_RotateXFApply(Rand_ZeroFloat(M_PIf * 2));
                    Matrix_MultVecZ(lightRayMaxScale, &velocity);
                    accel.x = velocity.x * -0.03f;
                    accel.y = velocity.y * -0.03f;
                    accel.z = velocity.z * -0.03f;
                    EnClearTag_CreateIsolatedLightRayEffect(
                        this, &pos, &velocity, &accel,
                        sLightRayScale[thisx->params] + Rand_ZeroFloat(sLightRayScale[thisx->params] * 0.5f),
                        sLightRayMaxScaleTarget[thisx->params], this->actor.world.rot.z, Rand_ZeroFloat(10.0f) + 20.0f);
                }
                return;
            }

            if ((this->actor.world.rot.x != 0) || (this->actor.world.rot.y != 0) || (this->actor.world.rot.z != 0)) {
                this->flashEnvColor.r = this->actor.world.rot.x;
                this->flashEnvColor.g = this->actor.world.rot.y;
                this->flashEnvColor.b = this->actor.world.rot.z;
            } else {
                this->flashEnvColor.r = 255;
                this->flashEnvColor.g = 0;
            }

            
            Actor_UpdateBgCheckInfo(play, &this->actor, 50.0f, 30.0f, 100.0f, UPDBGCHECKINFO_FLAG_4);
            pos = this->actor.world.pos;
            EnClearTag_CreateFlashEffect(this, &pos, sFlashMaxScale[thisx->params], this->actor.floorHeight);

            
            if (!(this->actor.bgCheckFlags & BGCHECKFLAG_WATER)) {
                if (thisx->params < 10) {
                    pos.y = this->actor.world.pos.y - 40.0f;

                    
                    if (thisx->params != CLEAR_TAG_POP) {
                        EnClearTag_CreateSmokeEffect(this, &pos, sSmokeScale[thisx->params]);
                    }

                    
                    pos.y = this->actor.floorHeight + 3.0f;
                    EnClearTag_CreateShockwaveEffect(this, &pos, sShockwaveMaxScale[thisx->params], 0);
                    EnClearTag_CreateShockwaveEffect(this, &pos, sShockwaveMaxScale[thisx->params], 3);
                    if (thisx->params == CLEAR_TAG_LARGE_EXPLOSION) {
                        EnClearTag_CreateShockwaveEffect(this, &pos, sShockwaveMaxScale[thisx->params], 6);
                    }
                }

                
                if (thisx->params != CLEAR_TAG_POP) {
                    pos.y = this->actor.world.pos.y;
                    for (i = 0; i < 18; i++) {
                        velocity.x = sinf(i * (33.0f / 40.0f)) * i * .5f;
                        velocity.z = cosf(i * (33.0f / 40.0f)) * i * .5f;
                        velocity.y = Rand_ZeroFloat(8.0f) + 7.0f;

                        velocity.x += Rand_CenteredFloat(0.5f);
                        velocity.z += Rand_CenteredFloat(0.5f);

                        accel.x = 0.0f;
                        accel.y = -1.0f;
                        accel.z = 0.0f;
                        EnClearTag_CreateDebrisEffect(this, &pos, &velocity, &accel,
                                                      sDebrisScale[thisx->params] +
                                                          Rand_ZeroFloat(sDebrisScale[thisx->params]),
                                                      this->actor.floorHeight);
                    }
                }
            }

            
            pos = this->actor.world.pos;
            for (i = 0; i < 44; i++) {
                lightRayMaxScale = sLightRayMaxScale[thisx->params] + Rand_ZeroFloat(sLightRayMaxScale[thisx->params]);
                Matrix_RotateYF(Rand_ZeroFloat(2 * M_PIf), MTXMODE_NEW);
                Matrix_RotateXFApply(Rand_ZeroFloat(2 * M_PIf));
                Matrix_MultVecZ(lightRayMaxScale, &velocity);
                accel.x = velocity.x * -0.03f;
                accel.y = velocity.y * -0.03f;
                accel.z = velocity.z * -0.03f;
                EnClearTag_CreateLightRayEffect(this, &pos, &velocity, &accel,
                                                sLightRayScale[thisx->params] +
                                                    Rand_ZeroFloat(sLightRayScale[thisx->params] * 0.5f),
                                                sLightRayMaxScaleTarget[thisx->params], Rand_ZeroFloat(10.0f) + 20.0f);
            }
        }

        
        EnClearTag_CreateSplashEffect(this, &pos, 0);
        EnClearTag_CreateSplashEffect(this, &pos, 2);
    }
}
