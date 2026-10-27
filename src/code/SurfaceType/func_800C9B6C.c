#include "types.h"

typedef struct {
    u8 pad0[4];
    u16 flags;
} SurfaceType;

extern SurfaceType *BgCheck_GetCollisionHeader(s32 arg0, s32 arg1);

s32 SurfaceType_IsFloorDekuFlower(s32 arg0, SurfaceType *arg1, s32 arg2) {
    u32 bit; // separate temporary: matches the ROM's register choice

    if (BgCheck_GetCollisionHeader(arg0, arg2) == NULL) {
        return 1;
    }
    bit = arg1->flags & 0x4000;
    return bit != 0;
}
