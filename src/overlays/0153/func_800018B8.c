// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_809385A8(ObjBean* this, PlayState* play) {
    s32 pad;
    s16 sp22;

    this->unk_1AC += 16000;
    this->unk_1AE -= 200;
    sp22 = 6372.0f - (Math_SinS(this->unk_1AC) * this->unk_1AE);
    this->dyna.actor.scale.y = Math_SinS(sp22) * 0.17434467f;
    this->dyna.actor.scale.x = this->dyna.actor.scale.z = Math_CosS(sp22) * 0.12207746f;
    if (this->unk_1AE < 0) {
        ref_func_80937C30(this);
        ref_func_80937FB0(this);
    }
}
