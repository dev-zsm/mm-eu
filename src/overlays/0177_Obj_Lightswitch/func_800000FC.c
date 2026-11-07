// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightswitch_SpawnEffects(ObjLightswitch* this, PlayState* play) {
    Vec3f effectPos;
    f32 sinResult;
    f32 cosResult;
    f32 tempResult;
    f32 tempResultDiff;
    f32 rand;
    s32 alpha;

    sinResult = Math_SinS(this->actor.shape.rot.y);
    cosResult = Math_CosS(this->actor.shape.rot.y);
    alpha = this->colorAlpha;

    if (alpha >= (100 << 6)) {
        tempResult = (1.0f - (alpha * (1.0f / (255 << 6)))) * 400.0f;
        tempResult = ((CLAMP_MAX(tempResult, 60.0f) - 30.0f) + 30.0f) * Rand_ZeroOne();
        tempResultDiff = tempResult - 30.0f;

        if (tempResult > 30.0f) {
            tempResult = 30.0f;
        } else {
            tempResult = SQ(30.0f) - SQ(tempResultDiff);
            tempResult = CLAMP_MIN(tempResult, SQ(10.0f));
            tempResult = sqrtf(tempResult);
        }

        tempResult = 2.0f * ((Rand_ZeroOne() - 0.5f) * tempResult);
        rand = ((30.0f - fabsf(tempResult)) * 0.5f) + (Rand_ZeroOne() * 10.0f);

        effectPos.x = this->actor.world.pos.x + ((rand * sinResult) + (tempResult * cosResult));
        effectPos.y = this->actor.world.pos.y + tempResultDiff + 10.0f;
        effectPos.z = this->actor.world.pos.z + ((rand * cosResult) - (tempResult * sinResult));

        EffectSsDeadDb_Spawn(play, &effectPos, &gZeroVec3f, &gZeroVec3f, &sLightswitchEffectPrimColor,
                             &sLightswitchEffectEnvColor, 100, 0, 9);
    }
}
