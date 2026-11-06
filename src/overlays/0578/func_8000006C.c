// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sc_ruppe.h"

s32 ref_func_80BD697C(s16 ruppeIndex) {
    switch (ruppeIndex) {
        case RUPEE_GREEN:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_53_04)) {
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_53_04);
                return true;
            }
            break;
        case RUPEE_BLUE:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_53_80)) {
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_53_80);
                return true;
            }
            break;
        case RUPEE_RED:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_54_01)) {
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_54_01);
                return true;
            }
            break;
        case RUPEE_ORANGE:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_54_02)) {
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_54_02);
                return true;
            }
            break;
        case RUPEE_PURPLE:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_54_04)) {
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_54_04);
                return true;
            }
            break;
        case RUPEE_UNUSED:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_54_08)) {
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_54_08);
                return true;
            }
            break;
    }
    return false;
}
