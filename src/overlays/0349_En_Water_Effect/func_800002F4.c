// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void EnWaterEffect_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnWaterEffect* this = (EnWaterEffect*)thisx;

    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->unk_DC4 = Rand_ZeroFloat(100.0f);

    if (this->actor.params == ENWATEREFFECT_TYPE_FALLING_ROCK_SPAWNER) {
        this->actor.update = ref_func_80A59C04;
        this->actor.draw = ref_func_80A5A184;
        this->unk_DC6 = Rand_ZeroFloat(100.0f) + 60.0f;
    } else if ((this->actor.params == ENWATEREFFECT_TYPE_GYORG_RIPPLES) ||
               (this->actor.params == ENWATEREFFECT_TYPE_GYORG_PRIMARY_SPRAY) ||
               (this->actor.params == ENWATEREFFECT_TYPE_GYORG_SECONDARY_SPRAY) ||
               (this->actor.params == ENWATEREFFECT_TYPE_GYORG_SHOCKWAVE)) {
        this->actor.update = ref_func_80A5A534;
        this->actor.draw = ref_func_80A5A6B8;
        this->actor.shape.rot.y = Rand_ZeroFloat(0x10000);
        Actor_SetScale(&this->actor, this->actor.shape.rot.z * 0.0002f);

        if (this->actor.params == ENWATEREFFECT_TYPE_GYORG_RIPPLES) {
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_WATER_EFFECT, this->actor.world.pos.x, this->actor.world.pos.y,
                        this->actor.world.pos.z, 0, 0, this->actor.shape.rot.z, ENWATEREFFECT_TYPE_GYORG_PRIMARY_SPRAY);
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_WATER_EFFECT, this->actor.world.pos.x, this->actor.world.pos.y,
                        this->actor.world.pos.z, 0, 0, this->actor.shape.rot.z,
                        ENWATEREFFECT_TYPE_GYORG_SECONDARY_SPRAY);
        } else if (this->actor.params == ENWATEREFFECT_TYPE_GYORG_PRIMARY_SPRAY) {
            this->unk_DC4 = -3;
        } else if (this->actor.params == ENWATEREFFECT_TYPE_GYORG_SECONDARY_SPRAY) {
            this->unk_DC4 = -6;
        } else if (this->actor.params == ENWATEREFFECT_TYPE_GYORG_SHOCKWAVE) {
            this->unk_DC4 = 23;
        }

        this->unk_E08[1] = 0.2f;
        this->unk_E18[1] = -0.017f;
        this->unk_E08[2] = 0.2f;
        this->unk_E18[2] = -0.018f;
        this->unk_E08[3] = 0.2f;
        this->unk_E18[3] = -0.019f;

        this->unk_DC8[1].y = 1.0f;
        this->unk_DC8[2].y = 1.0f;
        this->unk_DC8[3].y = 1.0f;

        this->unk_E2C = 255.0f;
        this->unk_E34 = 255.0f;
        this->unk_E30 = 200.0f;
        this->unk_E38 = 191.25f;
    }
}
