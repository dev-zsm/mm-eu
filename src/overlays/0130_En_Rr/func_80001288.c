// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FB088(EnRr* this, PlayState* play) {
    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 10, 0x1F4, 0);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    if (Player_GetMask(play) == PLAYER_MASK_STONE) {
        ref_func_808FA344(this);
        return;
    }

    switch (this->unk_1E1) {
        case 1:
            if (this->unk_1E6 == 0) {
                this->unk_1E1 = 2;
            }
            break;

        case 2:
            if (this->unk_1E6 == 0) {
                this->unk_324[4].unk_0C = 1.5f;
                this->unk_1E6 = 5;
                this->unk_1E1 = 3;
            }
            break;

        case 3:
            if (this->unk_1E6 == 0) {
                this->unk_1E6 = 2;
                this->unk_324[4].unk_04 = 2000.0f;
                this->unk_1E1 = 4;
            }
            break;

        case 4:
            if (this->unk_1E6 == 0) {
                this->unk_324[4].unk_0C = 0.8f;
                this->unk_1E6 = 20;
                this->unk_1E1 = 5;
            }
            break;

        case 5:
            if (this->unk_1E6 == 0) {
                ref_func_808FA344(this);
            }
            break;

        default:
            break;
    }
}
