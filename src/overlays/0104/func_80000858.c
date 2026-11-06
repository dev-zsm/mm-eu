// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wood02.h"

void ref_func_808C4458(EnWood02* this, PlayState* play, Vec3f* arg2, u16 arg3) {
    s32 pad[2];
    s32 sp24;

    if (this->unk_148 != 0) {
        if ((this->unk_144 == -1) || !Flags_GetCollectible(play, this->unk_144)) {
            if ((this->unk_148 < 0) && (this->unk_148 >= -0x10)) {
                if (arg3 & 1) {
                    Item_DropCollectibleRandom(play, &this->actor, arg2, ((-1 - this->unk_148) * 0x10) | 0x8000);
                } else {
                    Item_DropCollectibleRandom(play, &this->actor, arg2, (-1 - this->unk_148) * 0x10);
                }
            } else if (this->unk_148 > 0) {
                sp24 = ref_func_800A8150(this->unk_148 - 1);
                if (sp24 >= 0) {
                    if (this->unk_144 == -1) {
                        Item_DropCollectible(play, arg2, sp24);
                    } else {
                        Item_DropCollectible(play, arg2, ((this->unk_144 & 0x7F) << 8) | sp24);
                    }
                }
            }
        }
        this->unk_148 = 0;
    }
}
