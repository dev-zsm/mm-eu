// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lights.h"

void Lights_BindPointWithReference(Lights* lights, LightParams* params, Vec3f* pos) {
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 posDiff;
    f32 scale;
    Light* light;

    if ((pos != NULL) && (params->point.radius >= 1)) {
        xDiff = params->point.x - pos->x;
        yDiff = params->point.y - pos->y;
        zDiff = params->point.z - pos->z;
        scale = params->point.radius;
        posDiff = SQ(xDiff) + SQ(yDiff) + SQ(zDiff);

        if (SQ(scale) > posDiff) {
            light = Lights_FindSlot(lights);

            if (light != NULL) {
                posDiff = sqrtf(posDiff);
                scale = posDiff / scale;
                scale = 1 - SQ(scale);

                light->l.col[0] = params->point.color[0] * scale;
                light->l.colc[0] = light->l.col[0];
                light->l.col[1] = params->point.color[1] * scale;
                light->l.colc[1] = light->l.col[1];
                light->l.col[2] = params->point.color[2] * scale;
                light->l.colc[2] = light->l.col[2];

                scale = (posDiff < 1) ? 120 : 120 / posDiff;

                light->l.dir[0] = xDiff * scale;
                light->l.dir[1] = yDiff * scale;
                light->l.dir[2] = zDiff * scale;
            }
        }
    }
}
