// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_change.h"

void EffChange_SetColors(EffChange* this, s32 arg1) {
    arg1 *= 6;
    this->primColors[0] = ref_D_80A4C920[arg1];
    this->primColors[1] = ref_D_80A4C920[arg1 + 1];
    this->primColors[2] = ref_D_80A4C920[arg1 + 2];
    this->envColors[0] = ref_D_80A4C920[arg1 + 3];
    this->envColors[1] = ref_D_80A4C920[arg1 + 4];
    this->envColors[2] = ref_D_80A4C920[arg1 + 5];
}
