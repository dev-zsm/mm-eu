#include "types.h"

extern s32 BgCheck_RaycastFloorImpl(void *a, void *b, s32 mode, void *c, void *d, void *e, void *f, s32 flags, f32 scale, s32 zero);

s32 BgCheck_EntityRaycastFloor5_2(void *a, void *b, void *c, void *d, void *e, void *f) {
    return BgCheck_RaycastFloorImpl(a, b, 2, c, d, f, e, 0x1C, 1.0f, 0);
}
