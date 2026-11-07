// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ref_func_809A3A74(ObjPzlblock* this, PlayState* play) {
    s32 i;
    s32 sp20 = ref_func_809A3448(this);

    for (i = 0; i < ARRAY_COUNT(this->unk_16E); i++) {
        if (sp20 == i) {
            this->unk_16E[i]++;
        } else if (this->unk_16E[i] > 0) {
            this->unk_16E[i]--;
        }
    }

    if (sp20 != -1) {
        if ((this->unk_16E[sp20] >= 11) && ref_func_809A34E0(this, sp20) && ref_func_809A35EC(this, sp20)) {
            if (!ref_func_809A33E0(this, play, (this->dyna.pushForce > 0.0f) ? 90 : 120)) {
                ref_func_809A376C(this, sp20);
                ref_func_809A3BA4(this);
                return;
            }
        }

        GET_PLAYER(play)->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
    }
}
