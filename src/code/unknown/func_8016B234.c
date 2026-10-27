#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
s32 BgCheck_GetWaterSurfaceNoBgIdAlt(s32 a, s32 b, s32 c, s32 d, f32 *e, f32 *f);
f32 BgCheck_EntityRaycastFloor3(s32 a, f32 *b, f32 *c, Vec3f *d);
s32 func_8016B234(s32 a, Vec3f *p) {
    f32 sp3C;
    f32 sp38;
    Vec3f v;
    f32 sp28;
    s32 b;
    v = *p;
    b = a + 0x830;
    /* x and z are passed as raw words, as in the ROM */
    if (BgCheck_GetWaterSurfaceNoBgIdAlt(a, b, *(s32 *)&v.x, *(s32 *)&v.z, &v.y, &sp3C) == 1) {
        if (p->y < v.y) {
            if (BgCheck_EntityRaycastFloor3(b, &sp38, &sp28, &v) != -32000.0f) {
                return 1;
            }
        }
    }
    return 0;
}
