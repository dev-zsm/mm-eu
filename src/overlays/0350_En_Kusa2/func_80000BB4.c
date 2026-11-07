// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5BD14(EnKusa2* this, PlayState* play, s32 arg2) {
    static s32 ref_D_80A5EB24[] = {
        ITEM00_RUPEE_GREEN, ITEM00_RUPEE_GREEN, ITEM00_RUPEE_GREEN, ITEM00_RUPEE_GREEN, ITEM00_RUPEE_GREEN,
        ITEM00_RUPEE_GREEN, ITEM00_RUPEE_GREEN, ITEM00_RUPEE_GREEN, ITEM00_RUPEE_RED,
    };
    EnKusa2* kusa2 = this->unk_1C0;

    if (kusa2 != NULL) {
        if (kusa2->unk_1BC > 8) {
            kusa2->unk_1BC = 8;
        }
        Item_DropCollectible(play, &this->actor.world.pos, ref_D_80A5EB24[kusa2->unk_1BC]);
        kusa2->unk_1BC += arg2;
    }
}
