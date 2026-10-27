#include "types.h"

typedef struct {
    u8 pad0[4];
    u16 flags;
} SurfaceType;
extern s32 BgCheck_GetCollisionHeader(s32 colCtx, s32 bgId);
s32 SurfaceType_IsFloorConveyor(s32 colCtx, SurfaceType *surface, s32 bgId) {
    int new_var;
    if (BgCheck_GetCollisionHeader(colCtx, bgId) == 0) {
        return 1;
    }
    if (surface == 0) {
        return 0;
    }
    return (new_var = surface->flags & 0x2000) != 0;
}
