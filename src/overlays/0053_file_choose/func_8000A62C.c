// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_choose_NES.h"

void func_8000A62C(GameState* thisx) {
    static s16 ref_D_80814564 = 0;
    FileSelectState* this = (FileSelectState*)thisx;

    ref_D_80814564 += 2;

    if (ref_D_80814564 == 254) {
        this->configMode = this->nextConfigMode;
        ref_D_80814564 = 0;
    }
}
