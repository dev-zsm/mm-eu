// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

s32 EnKujiya_CheckBoughtTicket(void) {
    switch (CURRENT_DAY) {
        case 1:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_33_10)) {
                return true;
            }
            break;

        case 2:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_33_20)) {
                return true;
            }
            break;

        case 3:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_33_40)) {
                return true;
            }
            break;

        default:
            break;
    }
    return false;
}
