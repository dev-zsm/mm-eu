// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80938C1C(Actor* thisx, PlayState* play) {
    ObjBean* this = (ObjBean*)thisx;

    if (this->unk_1B2 > 0) {
        this->unk_1B2--;
    }

    if (this->unk_1DF > 0) {
        this->unk_1DF--;
        if (this->unk_1DF == 0) {
            Audio_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
        }
    }

    this->actionFunc(this, play);
}
