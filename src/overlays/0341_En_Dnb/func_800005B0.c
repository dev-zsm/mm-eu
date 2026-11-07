// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

void EnDnb_Update(Actor* thisx, PlayState* play) {
    EnDnb* this = (EnDnb*)thisx;
    s32 i;

    if (this->unk_0D30 == 0) {
        for (i = 0; i < ARRAY_COUNT(this->effects); i++) {
            ref_func_80A4FFE8(&this->effects[i], ((53 - i) / 18) * 4);
        }

        for (i = 0; i < ARRAY_COUNT(this->unk_0D38); i++) {
            this->unk_0D38[i].isEnabled = false;
        }
        this->unk_0D32 = 20;
        this->unk_0D30 = 100;
    } else if (DECR(this->unk_0D32) == 0) {
        if ((DECR(this->unk_0D34) == 0) && (this->unk_0D30 >= 21)) {
            this->unk_0D34 = 5;
            ref_func_80A500F8(this);
        }

        for (i = 0; i < ARRAY_COUNT(this->effects); i++) {
            ref_func_80A4FEBC(&this->effects[i], this->dyna.actor.world.pos.y);
        }

        this->unk_0D30--;
    }
    ref_func_80A5086C(this->unk_0D38);
}
