// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_kankyo.h"

void DemoKakyo_LostWoodsSparkleActionFunc(DemoKankyo* this, PlayState* play) {
    s32 pad;
    s32 i;
    f32 randSkyfishParticleNum;
    f32 repositionLimit; 
    f32 eyeToAtNormX;
    f32 eyeToAtNormY;
    f32 eyeToAtNormZ;
    f32 eyeToAtMag;
    f32 posCenterX;
    f32 posCenterY;
    f32 posCenterZ;
    Vec3f eyeToAt;
    Player* player = GET_PLAYER(play);

    if (play->roomCtx.unk7A[1] != 0) {
        if (play->envCtx.precipitation[PRECIP_SNOW_MAX] != 0) {
            play->envCtx.precipitation[PRECIP_SNOW_MAX]--;
        } else {
            Actor_Kill(&this->actor);
        }
    } else if (play->envCtx.precipitation[PRECIP_SNOW_MAX] < DEMOKANKYO_EFFECT_COUNT) {
        play->envCtx.precipitation[PRECIP_SNOW_MAX] += 16;
    }

    
    
    
    
    
    for (i = 0; i < play->envCtx.precipitation[PRECIP_SNOW_MAX]; i++) {
        repositionLimit = 130.0f;

        eyeToAt.x = play->view.at.x - play->view.eye.x;
        eyeToAt.y = play->view.at.y - play->view.eye.y;
        eyeToAt.z = play->view.at.z - play->view.eye.z;
        eyeToAtMag = sqrtf(SQXYZ(eyeToAt));
        eyeToAtNormX = eyeToAt.x / eyeToAtMag;
        eyeToAtNormY = eyeToAt.y / eyeToAtMag;
        eyeToAtNormZ = eyeToAt.z / eyeToAtMag;

        switch (this->effects[i].state) {
            case DEMO_KANKYO_STATE_INIT:
                this->effects[i].posBase.x = play->view.eye.x + (eyeToAtNormX * 80.0f);
                this->effects[i].posBase.y = play->view.eye.y + (eyeToAtNormY * 80.0f);
                this->effects[i].posBase.z = play->view.eye.z + (eyeToAtNormZ * 80.0f);

                this->effects[i].posOffset.x = (Rand_ZeroOne() - 0.5f) * 160.0f;
                this->effects[i].posOffset.y = 30.0f;
                this->effects[i].posOffset.z = (Rand_ZeroOne() - 0.5f) * 160.0f;

                this->effects[i].speedTarget = (Rand_ZeroOne() * 1.6f) + 0.5f;
                this->effects[i].alpha = 0;
                this->effects[i].alphaClock = Rand_ZeroOne() * 65535; 
                this->effects[i].scale = 0.1f;

                
                
                
                this->effects[i].speedClock.x = Rand_ZeroOne() * 360.0f;
                this->effects[i].speedClock.y = Rand_ZeroOne() * 360.0f;
                this->effects[i].speedClock.z = Rand_ZeroOne() * 360.0f;
                this->effects[i].pad50 = 0;
                this->effects[i].state += DEMO_KANKYO_STATE_SINGLE;
                break;

            case DEMO_KANKYO_STATE_SINGLE:
            case DEMO_KANKYO_STATE_SKYFISH:
                this->effects[i].alphaClock++;
                posCenterX = play->view.eye.x + (eyeToAtNormX * 80.0f);
                posCenterY = play->view.eye.y + (eyeToAtNormY * 80.0f);
                posCenterZ = play->view.eye.z + (eyeToAtNormZ * 80.0f);
                this->effects[i].posOffsetPrev.x = this->effects[i].posOffset.x;
                this->effects[i].posOffsetPrev.y = this->effects[i].posOffset.y;
                this->effects[i].posOffsetPrev.z = this->effects[i].posOffset.z;

                if (this->effects[i].state == DEMO_KANKYO_STATE_SINGLE) {

                    
                    
                    if (i < 32) {
                        if (Rand_ZeroOne() < 0.5f) {
                            this->effects[i].LostWoodsSkyFishSpeedXZ = TRUNCF_BINANG(Rand_ZeroOne() * 200.0f) + 200;
                        } else {
                            this->effects[i].LostWoodsSkyFishSpeedXZ = -200 - TRUNCF_BINANG(Rand_ZeroOne() * 200.0f);
                        }
                        this->effects[i].LostWoodsSkyFishPosOffsetMax = TRUNCF_BINANG(Rand_ZeroOne() * 50.0f) + 15;
                        this->effects[i].LostWoodsSkyFishSpeedY = ((Rand_ZeroOne() * 10.0f) + 10.0f) * 0.01f;

                        
                        
                        randSkyfishParticleNum = Rand_ZeroOne();
                        if (randSkyfishParticleNum < 0.2f) {
                            sLostWoodsSkyFishParticleNum = 1;
                        } else if (randSkyfishParticleNum < 0.2f) {
                            
                            sLostWoodsSkyFishParticleNum = 3;
                        } else if (randSkyfishParticleNum < 0.4f) {
                            sLostWoodsSkyFishParticleNum = 7;
                        } else {
                            sLostWoodsSkyFishParticleNum = 15;
                        }

                        if ((i & sLostWoodsSkyFishParticleNum) == 0) {
                            
                            this->effects[i].posOffset.y = 0.0f;
                        }
                        this->effects[i].state = DEMO_KANKYO_STATE_SKYFISH;
                        this->effects[i].speedTarget = 0.0f;
                    }

                    Math_SmoothStepToF(&this->effects[i].scale, 0.1, 0.1f, 0.001f, 0.00001f);
                    Math_SmoothStepToF(&this->effects[i].speed, this->effects[i].speedTarget, 0.5f, 0.2f, 0.02f);
                    this->effects[i].posOffset.x += sinf(this->effects[i].speedClock.x) * this->effects[i].speed;
                    this->effects[i].posOffset.y += sinf(this->effects[i].speedClock.y) * this->effects[i].speed;
                    this->effects[i].posOffset.z += sinf(this->effects[i].speedClock.z) * this->effects[i].speed;

                    switch ((i >> 1) & 3) {
                        case 0:
                            this->effects[i].speedClock.x += 0.008f;
                            this->effects[i].speedClock.y += 0.05f * Rand_ZeroOne();
                            this->effects[i].speedClock.z += 0.015f;
                            break;

                        case 1:
                            this->effects[i].speedClock.x += 0.01f * Rand_ZeroOne();
                            this->effects[i].speedClock.y += 0.05f * Rand_ZeroOne();
                            this->effects[i].speedClock.z += 0.005f * Rand_ZeroOne();
                            break;

                        case 2:
                            this->effects[i].speedClock.x += 0.01f * Rand_ZeroOne();
                            this->effects[i].speedClock.y += 0.4f * Rand_ZeroOne();
                            this->effects[i].speedClock.z += 0.004f * Rand_ZeroOne();
                            break;

                        case 3:
                            this->effects[i].speedClock.x += 0.01f * Rand_ZeroOne();
                            this->effects[i].speedClock.y += 0.08f * Rand_ZeroOne();
                            this->effects[i].speedClock.z += 0.05f * Rand_ZeroOne();
                            break;
                    }

                } else if (this->effects[i].state == DEMO_KANKYO_STATE_SKYFISH) {
                    if ((i & sLostWoodsSkyFishParticleNum) == 0) {
                        
                        Math_SmoothStepToF(&this->effects[i].scale, 0.25f, 0.1f, 0.001f, 0.00001f);

                        Math_SmoothStepToF(&this->effects[i].posBase.x, player->actor.world.pos.x, 0.5f, 1.0f, 0.2f);
                        Math_SmoothStepToF(&this->effects[i].posBase.y, player->actor.world.pos.y + 50.0f, 0.5f, 1.0f,
                                           0.2f);
                        Math_SmoothStepToF(&this->effects[i].posBase.z, player->actor.world.pos.z, 0.5f, 1.0f, 0.2f);

                        Math_SmoothStepToF(&this->effects[i].posOffset.x,
                                           Math_SinS(this->effects[i].LostWoodsSkyFishSpeedXZClock - 0x8000) *
                                               this->effects[i].LostWoodsSkyFishPosOffsetMax,
                                           0.5f, 2.0f, 0.2f);
                        Math_SmoothStepToF(&this->effects[i].posOffset.z,
                                           Math_CosS(this->effects[i].LostWoodsSkyFishSpeedXZClock - 0x8000) *
                                               this->effects[i].LostWoodsSkyFishPosOffsetMax,
                                           0.5f, 2.0f, 0.2f);
                        this->effects[i].LostWoodsSkyFishSpeedXZClock += this->effects[i].LostWoodsSkyFishSpeedXZ;
                        this->effects[i].posOffset.y += sinf(this->effects[i].speedClock.y);
                        this->effects[i].speedClock.x += 0.2f * Rand_ZeroOne(); 
                        this->effects[i].speedClock.y += this->effects[i].LostWoodsSkyFishSpeedY;
                        this->effects[i].speedClock.z += 0.1f * Rand_ZeroOne(); 

                        this->effects[i].posOffset.x =
                            Math_SinS(this->effects[i].LostWoodsSkyFishSpeedXZClock - 0x8000) *
                            this->effects[i].LostWoodsSkyFishPosOffsetMax;
                        this->effects[i].posOffset.z =
                            Math_CosS(this->effects[i].LostWoodsSkyFishSpeedXZClock - 0x8000) *
                            this->effects[i].LostWoodsSkyFishPosOffsetMax;
                    } else {
                        
                        Math_SmoothStepToF(&this->effects[i].scale, 0.1, 0.1f, 0.001f, 0.00001f);

                        
                        
                        Math_SmoothStepToF(&this->effects[i].speed, 1.5f, 0.5f, 0.1f, 0.0002f);

                        
                        
                        this->effects[i].posOffset.x = this->effects[i - 1].posOffsetPrev.x +
                                                       (this->effects[i - 1].posBase.x - this->effects[i].posBase.x);
                        this->effects[i].posOffset.y = this->effects[i - 1].posOffsetPrev.y +
                                                       (this->effects[i - 1].posBase.y - this->effects[i].posBase.y);
                        this->effects[i].posOffset.z = this->effects[i - 1].posOffsetPrev.z +
                                                       (this->effects[i - 1].posBase.z - this->effects[i].posBase.z);
                    }
                }

                if ((this->effects[i].state != DEMO_KANKYO_STATE_SKYFISH) &&
                    ((((this->effects[i].posBase.x + this->effects[i].posOffset.x) - posCenterX) > repositionLimit) ||
                     (((this->effects[i].posBase.x + this->effects[i].posOffset.x) - posCenterX) < -repositionLimit) ||
                     (((this->effects[i].posBase.y + this->effects[i].posOffset.y) - posCenterY) > repositionLimit) ||
                     (((this->effects[i].posBase.y + this->effects[i].posOffset.y) - posCenterY) < -repositionLimit) ||
                     (((this->effects[i].posBase.z + this->effects[i].posOffset.z) - posCenterZ) > repositionLimit) ||
                     (((this->effects[i].posBase.z + this->effects[i].posOffset.z) - posCenterZ) < -repositionLimit))) {
                    if (((this->effects[i].posOffset.x + this->effects[i].posBase.x) - posCenterX) > repositionLimit) {
                        this->effects[i].posOffset.x = 0.0f;
                        this->effects[i].posBase.x = posCenterX - repositionLimit;
                    }

                    if (((this->effects[i].posBase.x + this->effects[i].posOffset.x) - posCenterX) < -repositionLimit) {
                        this->effects[i].posOffset.x = 0.0f;
                        this->effects[i].posBase.x = posCenterX + repositionLimit;
                    }

                    if (((this->effects[i].posBase.y + this->effects[i].posOffset.y) - posCenterY) > 50.0f) {
                        this->effects[i].posOffset.y = 0.0f;
                        this->effects[i].posBase.y = posCenterY - 50.0f;
                    }

                    if (((this->effects[i].posBase.y + this->effects[i].posOffset.y) - posCenterY) < -50.0f) {
                        this->effects[i].posOffset.y = 0.0f;
                        this->effects[i].posBase.y = posCenterY + 50.0f;
                    }

                    if (((this->effects[i].posBase.z + this->effects[i].posOffset.z) - posCenterZ) > repositionLimit) {
                        this->effects[i].posOffset.z = 0.0f;
                        this->effects[i].posBase.z = posCenterZ - repositionLimit;
                    }

                    if (((this->effects[i].posBase.z + this->effects[i].posOffset.z) - posCenterZ) < -repositionLimit) {
                        this->effects[i].posOffset.z = 0.0f;
                        this->effects[i].posBase.z = posCenterZ + repositionLimit;
                    }
                }
                break;

            case DEMO_KANKYO_STATE_DISABLED:
                this->effects[i].state = DEMO_KANKYO_STATE_INIT;
                break;
        }
    }
}
