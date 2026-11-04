// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe3.h"

void TransitionWipe3_SetType(void* thisx, s32 type) {
    TransitionWipe3* this = (TransitionWipe3*)thisx;

    if (type & TRANS_TYPE_SET_PARAMS) {
        this->speedType = TRANS3_GET_SPEED(type);
        this->texIndex = TRANS3_GET_TEX_INDEX(type);
        this->colorType = TRANS3_GET_COLOR(type);
    } else if (type == TRANS_INSTANCE_TYPE_FILL_OUT) {
        this->dir = TRANS_WIPE3_DIR_OUT;
    } else {
        this->dir = TRANS_WIPE3_DIR_IN;
    }
}
