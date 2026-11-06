// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateGrowingWindCapsule(EnTest7* this, PlayState* play) {
    this->flags |= OWL_WARP_FLAGS_DRAW_WIND_CAPSULE;

    if (this->windCapsule.unk_04 < 11.0f) {
        this->windCapsule.unk_04 += 0.3f;
        this->windCapsule.xzScale = ((this->windCapsule.unk_00 * -0.45f) / 11.0f) + 0.7f;
        this->windCapsule.yScale = ((this->windCapsule.unk_00 * -0.29999998f) / 11.0f) + 0.7f;
    }

    if (this->windCapsule.unk_00 < 11.0f) {
        this->windCapsule.unk_00 += 1.0f;
        if (this->windCapsule.unk_00 > 6.0f) {
            Player* player = GET_PLAYER(play);

            this->flags &= ~OWL_WARP_FLAGS_DRAW_WINGS;
            player->actor.draw = NULL;
        }
    } else if (this->timer > 86) {
        EnTest7_SetupAction(this, EnTest7_WarpCsPart4);
        this->flags &= ~OWL_WARP_FLAGS_8;
        this->windCapsule.yaw -= 0x2EE0;
    } else {
        this->windCapsule.yaw -= 0x2EE0;
    }
}
