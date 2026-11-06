// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Dead(EnSlime* this, PlayState* play) {
    s32 i;
    Vec3f velocity;
    Vec3f effectPos;
    f32 randFloat;
    s32 randSign;

    if (Math_StepToF(&this->actor.scale.x, 0.0f, 0.002f)) {
        effectPos.x = this->actor.world.pos.x;
        effectPos.y = this->actor.world.pos.y + 20.0f;
        effectPos.z = this->actor.world.pos.z;
        EffectSsGSplash_Spawn(play, &effectPos, NULL, NULL, 1, 800);

        for (i = 0; i < 15; i++) {
            randFloat = Rand_ZeroOne();
            randSign = Rand_ZeroOne() < 0.5f ? -1 : 1;
            velocity.x = randSign * ((randFloat * 2.5f) + 2.0f);

            randFloat = Rand_ZeroOne();
            randSign = Rand_ZeroOne() < 0.5f ? -1 : 1;
            velocity.z = randSign * ((randFloat * 2.5f) + 2.0f);

            velocity.y = (Rand_ZeroOne() * 6.0f) + 2.0f;
            EffectSsDtBubble_SpawnCustomColor(play, &effectPos, &velocity, &sBubbleAccel, &sBubblePrimColor,
                                              &sBubbleEnvColor, Rand_S16Offset(40, 20), 20, 0);
        }

        if (this->actor.params == EN_SLIME_TYPE_YELLOW) {
            Item_DropCollectible(play, &this->actor.world.pos, ITEM00_ARROWS_10);
        } else if (this->actor.params == EN_SLIME_TYPE_GREEN) {
            Item_DropCollectible(play, &this->actor.world.pos, ITEM00_MAGIC_JAR_SMALL);
        } else if (this->actor.params == EN_SLIME_TYPE_RED) {
            Item_DropCollectible(play, &this->actor.world.pos, ITEM00_RECOVERY_HEART);
        }
        EnSlime_SetupWaitForRevive(this);
    }
    this->actor.scale.y = this->actor.scale.x;
    this->actor.scale.z = this->actor.scale.x;
}
