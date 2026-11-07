// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80938504(ObjBean* this, PlayState* play) {
    this->unk_1AC -= 2400;
    this->dyna.actor.scale.y = Math_SinS(this->unk_1AC) * 0.17434467f;
    this->dyna.actor.scale.x = this->dyna.actor.scale.z = Math_CosS(this->unk_1AC) * 0.12207746f;
    if (this->unk_1AC < 6372) {
        ref_func_80938588(this);
    }
}
