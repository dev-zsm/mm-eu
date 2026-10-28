// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    u8 pad0[8];
    s16 nx, ny, nz;
} Poly;
typedef struct {
    u8 pad0[0x8C];
    u8 *play;
} Camera;

extern f32 D_801D4E80;
extern f32 BgCheck_EntityRaycastFloor3(void *colCtx, Poly **poly, s32 bgId, void *pos);

f32 Camera_GetFloorYNorm(Camera *camera, Vec3f *norm, void *pos, s32 bgId) {
    s32 pad;
    Poly *poly;
    f32 y;
    f32 sc;

    y = BgCheck_EntityRaycastFloor3(camera->play + 0x830, &poly, bgId, pos);
    if (y == -32000.0f) {
        norm->x = 0.0f;
        norm->z = 0.0f;
        norm->y = 1.0f;
    } else {
        sc = D_801D4E80;
        norm->x = poly->nx * sc;
        norm->y = poly->ny * sc;
        norm->z = poly->nz * sc;
    }
    return y;
}
