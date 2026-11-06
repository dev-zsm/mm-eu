// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B828E4(BgDblueBalance* this, PlayState* play) {
    if (Flags_GetSwitch(play, BGDBLUEBALANCE_GET_SWITCH_FLAG(&this->dyna.actor)) && (this->unk_17D <= 0)) {
        if (this->unk_183 >= 252) {
            this->unk_183 = 255;
        } else {
            this->unk_183 += 3;
        }
    } else if (this->unk_183 < 7) {
        this->unk_183 = 0;
    } else {
        this->unk_183 -= 6;
    }
}
