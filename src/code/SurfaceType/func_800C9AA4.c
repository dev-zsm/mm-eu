#include "types.h"

typedef struct {
    u16 unk0;
    u16 flags;
} SurfaceType;

s32 BgCheck_GetCollisionHeader(u8 *arg0, s32 arg1);

s32 SurfaceType_IsIgnoredByEntities(u8 *arg0, SurfaceType *arg1, s32 arg2) {
    s32 masked;

    if (BgCheck_GetCollisionHeader(arg0, arg2) == 0) {
        return 1;
    }
    masked = arg1->flags & 0x4000;
    return masked != 0;
}
