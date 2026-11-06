// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_part.h"

void ref_func_80865390(EnPart* this, PlayState* play) {
    this->actionFuncIndex = 1;
    this->actor.world.rot.y = Rand_ZeroOne() * 20000.0f;
    switch (this->actor.params) {
        case ENPART_TYPE_1:
        case ENPART_TYPE_4:
            this->unk146 += TRUNCF_BINANG(Rand_ZeroOne() * 17.0f) + 5;
            this->actor.velocity.y = Rand_ZeroOne() * 5.0f + 4.0f;
            this->actor.gravity = -0.6f - (Rand_ZeroOne() * 0.5f);
            this->unk14C = 0.15f;
            break;

        case ENPART_TYPE_15:
            this->actor.world.rot.y = this->actor.parent->shape.rot.y + 0x8000;
            this->unk146 = 100;
            this->actor.velocity.y = 7.0f;
            this->actor.speed = 2.0f;
            this->actor.gravity = -1.0f;
            break;

        default:
            break;
    }
}
