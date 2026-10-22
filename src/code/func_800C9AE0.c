// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    u16 unk2;
} SurfaceEntry;

s32 BgCheck_GetCollisionHeader(s32, s32);

s32 SurfaceType_IsIgnoredByProjectiles(s32 a0, SurfaceEntry *arg1, s32 a2) {
    if (BgCheck_GetCollisionHeader(a0, a2) == 0) {
        return 1;
    }
    {
        s32 v = arg1->unk2 & 0x8000;
        return v != 0;
    }
}
