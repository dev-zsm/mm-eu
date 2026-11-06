// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

s32 ref_func_8089F908(EnBubble* this) {
    this->modelWidth += 1.0f / 12.0f;
    this->modelHeight += 1.0f / 12.0f;

    if (DECR(this->explosionCountdown) != 0) {
        return false;
    } else {
        return true;
    }
}
