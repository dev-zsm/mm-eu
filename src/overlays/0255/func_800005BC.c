// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

void ref_func_809A477C(ObjToge* this, PlayState* play) {
    if (this->unk_1B2 > 0) {
        this->unk_1B2--;
    }

    if (this->unk_1B0 >= 0x1770) {
        this->unk_1B0 = 0x1770;
        ref_func_809A488C(this);
    } else if ((this->unk_1B0 > 0) || (this->unk_1B2 <= 0)) {
        this->unk_1B0 += 200;
    }

    if (!this->unk_1B4) {
        this->actor.shape.rot.y += this->unk_1B0;
    }
}
