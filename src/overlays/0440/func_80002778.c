// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_ArriveCsPart2(EnTest7* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Player* player2 = GET_PLAYER(play);
    Vec3f featherPos;

    Actor_PlaySfx_Flagged(&this->actor, NA_SE_PL_WARP_WING_ROLL_2 - SFX_FLAG);

    featherPos = this->actor.world.pos;

    EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);
    EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);

    this->windCapsule.unk_04 = 70 - this->timer;
    if (this->timer > 70) {
        EnTest7_SetupAction(this, EnTest7_ArriveCsPart3);
    }

    if (this->windCapsule.unk_04 > 11.0f) {
        f32 temp = this->windCapsule.unk_04 - 11.0f;

        this->windCapsule.xzScale = ((-0.35f * temp) / 19.0f) + 0.4f;
        this->windCapsule.yScale = ((-0.35f * temp) / 19.0f) + 0.4f;
        this->windCapsule.yaw += 0x2EE0;
    } else {
        player2->actor.draw = this->playerDrawFunc;
        this->windCapsule.unk_00 = this->windCapsule.unk_04;
        this->windCapsule.xzScale = ((this->windCapsule.unk_04 * -0.29999998f) / 11.0f) + 0.7f;
        this->windCapsule.yScale = ((this->windCapsule.unk_04 * -0.29999998f) / 11.0f) + 0.7f;
        player->stateFlags2 &= ~PLAYER_STATE2_20000000;
    }
}
