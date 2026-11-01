#include "types.h"
#include "code_funcs.h"

typedef struct { u8 pad0[0x1C]; void *unk1C; s32 unk20; } Info;

s32 BgCheck_GetBgCamCount(void *a, void *b, s32 c) {
    Info *i = BgCheck_GetCollisionHeader(a, c);
    register s32 t;

    if (i == 0) {
        return 0;
    }
    t = i->unk20;
    if (t == 0) {
        return 0;
    }
    t = (s32)i->unk1C;
    if (t == 0) {
        return 0;
    }
    return BgCheck_GetBgCamCountImpl(a, SurfaceType_GetBgCamIndex(a, b, c), c);
}
