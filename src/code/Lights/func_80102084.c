// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lights.h"

void Lights_BindDirectional(Lights* lights, LightParams* params, void* unused) {
    Light* light = Lights_FindSlot(lights);

    if (light != NULL) {
        light->l.col[0] = params->dir.color[0];
        light->l.colc[0] = light->l.col[0];
        light->l.col[1] = params->dir.color[1];
        light->l.colc[1] = light->l.col[1];
        light->l.col[2] = params->dir.color[2];
        light->l.colc[2] = light->l.col[2];
        light->l.dir[0] = params->dir.x;
        light->l.dir[1] = params->dir.y;
        light->l.dir[2] = params->dir.z;
        light->l.pad1 = 0; 
    }
}
