// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

s32 EnBubble_Explosion(EnBubble* this, PlayState* play) {
    static Color_RGBA8 sEffectPrimColor = { 255, 255, 255, 255 };
    static Color_RGBA8 sEffectEnvColor = { 150, 150, 150, 0 };
    s32 i;
    Vec3f effectAccel = { 0.0f, -0.5f, 0.0f };
    Vec3f effectVelocity;
    Vec3f effectPos;

    Math_SmoothStepToF(&this->modelWidth, 4.0f, 0.1f, 1000.0f, 0.0f);
    Math_SmoothStepToF(&this->modelHeight, 4.0f, 0.1f, 1000.0f, 0.0f);
    Math_SmoothStepToF(&this->modelRotSpeed, 54.0f, 0.1f, 1000.0f, 0.0f);
    Math_SmoothStepToF(&this->modelEllipticity, 0.2f, 0.1f, 1000.0f, 0.0f);
    this->actor.shape.yOffset = (this->modelHeight + 1.0f) * 16.0f;

    if (DECR(this->explosionCountdown) != 0) {
        return -1;
    }
    effectPos.x = this->actor.world.pos.x;
    effectPos.y = this->actor.world.pos.y + this->actor.shape.yOffset;
    effectPos.z = this->actor.world.pos.z;
    for (i = 0; i < 20; i++) {
        effectVelocity.x = (Rand_ZeroOne() - 0.5f) * 7.0f;
        effectVelocity.y = Rand_ZeroOne() * 7.0f;
        effectVelocity.z = (Rand_ZeroOne() - 0.5f) * 7.0f;
        EffectSsDtBubble_SpawnCustomColor(play, &effectPos, &effectVelocity, &effectAccel, &sEffectPrimColor,
                                          &sEffectEnvColor, Rand_S16Offset(100, 50), 25, 0);
    }
    Item_DropCollectibleRandom(play, NULL, &this->actor.world.pos, 0x50);
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    return Rand_S16Offset(90, 60);
}
