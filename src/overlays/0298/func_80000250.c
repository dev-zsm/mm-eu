// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_UpdateSettleRotation(s16* settleRotZ, s16* settleAngle, f32* settleScale, f32 scaleStep) {
    *settleAngle += 0x32C8;
    Math_StepToF(settleScale, 0.0f, scaleStep);
    *settleRotZ += TRUNCF_BINANG(Math_SinS(*settleAngle) * *settleScale);
}
