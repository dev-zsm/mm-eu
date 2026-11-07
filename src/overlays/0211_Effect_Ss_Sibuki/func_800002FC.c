// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_sibuki.h"

void EffectSsSibuki_Update(PlayState* play, u32 index, EffectSs* this) {
    Player* player = GET_PLAYER(play);
    s32 pad[2];
    f32 xzVelScale;

    if (this->pos.y <= player->actor.floorHeight) {
        this->life = 0;
    }

    if (this->rMoveDelay != 0) {
        this->rMoveDelay--;

        if (this->rMoveDelay == 0) {
            s16 yaw = Camera_GetInputDirYaw(Play_GetCamera(play, CAM_ID_MAIN));

            xzVelScale = ((200.0f + KREG(20)) * 0.01f) + ((0.1f * Rand_ZeroOne()) * (KREG(23) + 20.0f));

            if (this->rDirection != 0) {
                xzVelScale *= -1.0f;
            }

            this->velocity.x = Math_CosS(yaw) * xzVelScale;
            this->velocity.z = -Math_SinS(yaw) * xzVelScale;

            this->velocity.y = ((700.0f + KREG(21)) * 0.01f) + ((0.1f * Rand_ZeroOne()) * (KREG(24) + 20.0f));
            this->accel.y = ((-100.0f + KREG(22)) * 0.01f) + ((0.1f * Rand_ZeroOne()) * KREG(25));

            if (KREG(3) != 0) {
                this->velocity.x *= (KREG(3) * 0.01f);
                this->velocity.y *= (KREG(3) * 0.01f);
                this->velocity.z *= (KREG(3) * 0.01f);
                this->accel.y *= (KREG(4) * 0.01f);
            }
        }
    } else {
        if (this->rScale != 0) {
            this->rScale = (this->rScale - KREG(26)) - 3;
        }
    }
}
