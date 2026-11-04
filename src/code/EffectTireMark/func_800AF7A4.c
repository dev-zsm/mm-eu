// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_tire_mark.h"

void EffectTireMark_SetVertices(Vtx* vtx, EffectTireMarkElement* elem, s32 i, s32 alpha) {
    s32 i1 = i * 2;
    s32 i2 = i * 2 + 1;

    vtx[i1].v.ob[0] = elem->p1.x;
    vtx[i1].v.ob[1] = elem->p1.y;
    vtx[i1].v.ob[2] = elem->p1.z;
    vtx[i1].v.tc[0] = 2048;
    vtx[i1].v.tc[1] = 0;
    vtx[i1].v.cn[0] = 255;
    vtx[i1].v.cn[1] = 255;
    vtx[i1].v.cn[2] = 255;
    vtx[i1].v.cn[3] = alpha;

    vtx[i2].v.ob[0] = elem->p2.x;
    vtx[i2].v.ob[1] = elem->p2.y;
    vtx[i2].v.ob[2] = elem->p2.z;
    vtx[i2].v.tc[0] = 2048;
    vtx[i2].v.tc[1] = 1024;
    vtx[i2].v.cn[0] = 255;
    vtx[i2].v.cn[1] = 255;
    vtx[i2].v.cn[2] = 255;
    vtx[i2].v.cn[3] = alpha;
}
