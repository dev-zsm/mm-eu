// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void ref_func_80B7F0D0(BgIkanaBlock* this, PlayState* play) {
    s32 sp24 = 0;
    s32 phi_v1;

    ref_func_80B7EA60(this);
    ref_func_80B7EB30(this);

    if (this->unk_17C & 4) {
        sp24 = 1;
    } else if (ref_func_80B7ECFC(this, play)) {
        sp24 = 2;
    }

    if ((sp24 != 2) && (this->unk_17A & (0x8 | 0x4 | 0x2 | 0x1))) {
        Player* player = GET_PLAYER(play);

        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
    }

    if (sp24 == 1) {
        ref_func_80B7F360(this);
    } else if (sp24 == 2) {
        ref_func_80B7F1A8(this);
    }
}
