// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lights.h"

void Lights_BindPoint(Lights* lights, LightParams* params, PlayState* play) {
    Light* light;
    f32 kq = params->point.radius;
    Vec3f pos;
    Vec3f adjustedPos;
    s32 pad;

    if (kq > 0.0f) {
        pos.x = params->point.x;
        pos.y = params->point.y;
        pos.z = params->point.z;
        SkinMatrix_Vec3fMtxFMultXYZ(&play->viewProjectionMtxF, &pos, &adjustedPos);
        if ((-kq < adjustedPos.z) && ((600.0f + kq) > adjustedPos.z) && ((fabsf(adjustedPos.x) - kq) < 400.0f) &&
            ((fabsf(adjustedPos.y) - kq) < 400.0f)) {
            light = Lights_FindSlot(lights);
            if (light != NULL) {
                kq = 4500000.0f / SQ(kq);
                if (kq > 255.0f) {
                    kq = 255.0f;
                } else if (20.0f > kq) {
                    kq = 20.0f;
                }

                light->p.col[0] = params->point.color[0];
                light->p.colc[0] = light->p.col[0];

                light->p.col[1] = params->point.color[1];
                light->p.colc[1] = light->p.col[1];

                light->p.col[2] = params->point.color[2];
                light->p.colc[2] = light->p.col[2];

                light->p.pos[0] = params->point.x;
                light->p.pos[1] = params->point.y;
                light->p.pos[2] = params->point.z;

                light->p.kc = 8;
                light->p.kl = -1;
                light->p.kq = (s32)kq;
            }
        }
    }
}
