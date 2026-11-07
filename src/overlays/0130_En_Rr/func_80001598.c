// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FB398(EnRr* this, PlayState* play) {
    s32 i;
    s16 phi_v1;

    this->unk_1EC--;
    if (this->unk_1EC == 0) {
        ref_func_808FA870(this);
        return;
    }

    if (this->drawDmgEffType == ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_SMALL) {
        if (this->unk_1EC & 2) {
            phi_v1 = 1000;
        } else {
            phi_v1 = -1000;
        }
    } else {
        if (this->unk_1EC & 8) {
            phi_v1 = 5000;
        } else {
            phi_v1 = -5000;
        }
    }

    for (i = 1; i < ARRAY_COUNT(this->unk_324); i++) {
        this->unk_324[i].unk_18 = phi_v1;
    }
}
