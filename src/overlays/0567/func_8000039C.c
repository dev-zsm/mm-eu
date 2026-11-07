// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void EffKamejimaWave_SetVtxAlpha(u8 alpha) {
    Vtx* vtx = Lib_SegmentedToVirtual(&gTurtleWaveVtx);

    vtx[2].v.cn[3] = alpha;
    vtx[6].v.cn[3] = alpha;
    vtx[8].v.cn[3] = alpha;
    vtx[9].v.cn[3] = alpha;
    vtx[12].v.cn[3] = alpha;
    vtx[16].v.cn[3] = alpha;
    vtx[18].v.cn[3] = alpha;
    vtx[19].v.cn[3] = alpha;
}
