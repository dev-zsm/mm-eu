// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

u32 ref_func_80BB9A1C(ObjChan* this, f32 arg1) {
    f32 temp_f6;
    f32 sp20;

    sp20 = Math_SinS(this->unk1D4) * this->unk1D0;
    temp_f6 = (Math_CosS(this->unk1D4) * BINANG_TO_RAD_ALT2(400) * this->unk1D0) + arg1;
    if (temp_f6 != 0.0f) {
        this->unk1D4 = RAD_TO_BINANG(Math_FAtan2F(sp20 * BINANG_TO_RAD_ALT2(400), temp_f6));
    } else if (sp20 >= 0.0f) {
        this->unk1D4 = 0x4000;
    } else {
        this->unk1D4 = -0x4000;
    }
    if (Math_CosS(this->unk1D4) != 0.0f) {
        this->unk1D0 = (temp_f6 / (Math_CosS(this->unk1D4) * BINANG_TO_RAD_ALT2(400)));
    } else {
        this->unk1D0 = sp20;
    }
    return 0;
}
