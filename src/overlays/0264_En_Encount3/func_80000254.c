// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount3.h"

void ref_func_809AD194(EnEncount3* this, PlayState* play) {
    if (this->unk14E == 0) {
        this->unk178 = 0.0f;
        if (this->switchFlag > SWITCH_FLAG_NONE) {
            Flags_SetSwitch(play, this->switchFlag);
        }
        this->actionFunc = ref_func_809AD1EC;
    }
}
