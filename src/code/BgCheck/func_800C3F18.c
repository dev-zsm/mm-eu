#include "types.h"
#include "code_funcs.h"


s32 BgCheck_EntityRaycastFloor5_2(void *a, void *b, void *c, void *d, void *e, void *f) {
    return BgCheck_RaycastFloorImpl(a, b, 2, c, d, f, e, 0x1C, 1.0f, 0);
}
