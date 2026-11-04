// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_kankyo.h"

void DemoKakyo_MoonSparklesActionFunc(DemoKankyo* this, PlayState* play) {
    s32 i;
    Vec3f eyeToAt;
    f32 eyeToAtNormX;
    f32 eyeToAtNormY;
    f32 eyeToAtNormZ;
    f32 eyeToAtMag;
    f32 halfScreenWidth;
    f32 randZeroOne;
    f32 pad0;
    Vec3f newEye;
    f32 halfScreenHeight;
    s32 pad1;
    Vec3f worldPos;

    if (play->envCtx.precipitation[PRECIP_SNOW_MAX] < DEMOKANKYO_EFFECT_COUNT) {
        play->envCtx.precipitation[PRECIP_SNOW_MAX] += 16;
    }

    eyeToAt.x = play->view.at.x - play->view.eye.x;
    eyeToAt.y = play->view.at.y - play->view.eye.y;
    eyeToAt.z = play->view.at.z - play->view.eye.z;
    eyeToAtMag = sqrtf(SQXYZ(eyeToAt));
    eyeToAtNormX = eyeToAt.x / eyeToAtMag;
    eyeToAtNormY = eyeToAt.y / eyeToAtMag;
    eyeToAtNormZ = eyeToAt.z / eyeToAtMag;

    halfScreenHeight = SCREEN_HEIGHT / 2;

    for (i = 0; i < play->envCtx.precipitation[PRECIP_SNOW_MAX]; i++) {
        switch (this->effects[i].state) {
            case DEMO_KANKYO_STATE_INIT:
                this->effects[i].posBase.x = play->view.eye.x + (eyeToAtNormX * halfScreenHeight);
                this->effects[i].posBase.y = play->view.eye.y + (eyeToAtNormY * halfScreenHeight);
                this->effects[i].posBase.z = play->view.eye.z + (eyeToAtNormZ * halfScreenHeight);

                this->effects[i].posOffset.x = (Rand_ZeroOne() - 0.5f) * (2.0f * halfScreenHeight);
                this->effects[i].posOffset.y = (Rand_ZeroOne() - 0.5f) * (2.0f * halfScreenHeight);
                this->effects[i].posOffset.z = (Rand_ZeroOne() - 0.5f) * (2.0f * halfScreenHeight);

                this->effects[i].speedTarget = (Rand_ZeroOne() * 1.6f) + 0.5f;
                this->effects[i].alpha = 0;
                this->effects[i].alphaClock = (Rand_ZeroOne() * 65535);
                this->effects[i].scale = 0.2f;

                
                
                
                this->effects[i].speedClock.x = Rand_ZeroOne() * 360.0f;
                this->effects[i].speedClock.y = Rand_ZeroOne() * 360.0f;
                this->effects[i].speedClock.z = Rand_ZeroOne() * 360.0f;

                this->effects[i].pad50 = 0;
                this->effects[i].state += DEMO_KANKYO_STATE_SINGLE;
                break;

            case DEMO_KANKYO_STATE_SINGLE:
            case DEMO_KANKYO_STATE_SKYFISH:
                this->effects[i].alphaClock++;

                if (this->actor.params == DEMO_KANKYO_TYPE_MOON) { 
                    this->effects[i].posBase.y =
                        play->view.eye.y + (eyeToAtNormY * halfScreenHeight) + (SCREEN_HEIGHT / 3);
                }

                newEye.x = play->view.eye.x + (eyeToAtNormX * halfScreenHeight);
                newEye.y = play->view.eye.y + (eyeToAtNormY * halfScreenHeight);
                newEye.z = play->view.eye.z + (eyeToAtNormZ * halfScreenHeight);

                Math_SmoothStepToF(&this->effects[i].scale, 0.2f, 0.1f, 0.001f, 0.00001f);
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

                if (((this->effects[i].posBase.x + this->effects[i].posOffset.x) - newEye.x) > halfScreenHeight) {
                    this->effects[i].posBase.x = newEye.x - halfScreenHeight;
                }

                if (((this->effects[i].posBase.x + this->effects[i].posOffset.x) - newEye.x) < -halfScreenHeight) {
                    this->effects[i].posBase.x = newEye.x + halfScreenHeight;
                }

                worldPos.x = this->effects[i].posBase.x + this->effects[i].posOffset.x;
                worldPos.y = this->effects[i].posBase.y + this->effects[i].posOffset.y;
                worldPos.z = this->effects[i].posBase.z + this->effects[i].posOffset.z;

                randZeroOne = Math_Vec3f_DistXZ(&worldPos, &play->view.eye) / 200.0f;
                randZeroOne = CLAMP(randZeroOne, 0.0f, 1.0f);
                halfScreenWidth = 100.0f + randZeroOne + 60.0f; 

                
                if (halfScreenWidth < ((this->effects[i].posBase.y + this->effects[i].posOffset.y) - newEye.y)) {
                    this->effects[i].posBase.y = newEye.y - halfScreenWidth;
                }

                if (((this->effects[i].posBase.y + this->effects[i].posOffset.y) - newEye.y) < -halfScreenWidth) {
                    this->effects[i].posBase.y = newEye.y + halfScreenWidth;
                }

                if (((this->effects[i].posBase.z + this->effects[i].posOffset.z) - newEye.z) > halfScreenHeight) {
                    this->effects[i].posBase.z = newEye.z - halfScreenHeight;
                }

                if (((this->effects[i].posBase.z + this->effects[i].posOffset.z) - newEye.z) < -halfScreenHeight) {
                    this->effects[i].posBase.z = newEye.z + halfScreenHeight;
                }

                break;

            case DEMO_KANKYO_STATE_DISABLED:
                this->effects[i].state = DEMO_KANKYO_STATE_INIT;
                break;
        }
    }
}
