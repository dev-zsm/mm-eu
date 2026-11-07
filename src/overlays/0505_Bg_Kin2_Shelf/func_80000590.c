// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

void ref_func_80B700C0(BgKin2Shelf* this, PlayState* play) {
    s16 temp_v0;
    u8 phi_v0_2;

    if (fabsf(this->dyna.pushForce) > 0.1f) {
        temp_v0 = this->dyna.yRotation - this->dyna.actor.shape.rot.y;
        if (this->dyna.pushForce < 0.0f) {
            temp_v0 = BINANG_ROT180(temp_v0);
        }

        if ((temp_v0 < -0x6000) || (temp_v0 >= 0x6000)) {
            phi_v0_2 = 4;
        } else if (temp_v0 < -0x2000) {
            phi_v0_2 = 8;
        } else if (temp_v0 < 0x2000) {
            phi_v0_2 = 1;
        } else {
            phi_v0_2 = 2;
        }

        if ((phi_v0_2 == this->unk_164) || (this->unk_164 == 0)) {
            this->unk_164 = phi_v0_2;
            this->unk_165++;
        } else {
            this->unk_165 = 0;
            this->unk_164 = 0;
        }

        if (ref_func_80B6FF28(this, play)) {
            if (this->unk_164 & (0x8 | 0x2)) {
                ref_func_80B70214(this);
            } else {
                ref_func_80B70498(this);
            }
        } else {
            Player* player = GET_PLAYER(play);

            player->stateFlags2 &= ~PLAYER_STATE2_10;
            this->dyna.pushForce = 0.0f;
        }
    } else {
        this->unk_165 = 0;
        this->unk_164 = 0;
    }
}
