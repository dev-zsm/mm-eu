// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0x1C];
    u32 unk1C;
    u32 unk20;
} Ctx;
typedef struct { u32 x, y, z; } V;
s32 BgCheck_PosInStaticBoundingBox(Ctx *, s32);
void BgCheck_GetStaticLookupIndicesFromPos(Ctx *, s32, V *);
s32 BgCheck_GetStaticLookup(Ctx *ctx, s32 arg1, s32 arg2) {
    V v;
    u32 c;
    if (BgCheck_PosInStaticBoundingBox(ctx, arg2) == 0) {
        return 0;
    }
    BgCheck_GetStaticLookupIndicesFromPos(ctx, arg2, &v);
    c = ctx->unk1C;
    return v.z * c * ctx->unk20 * 6 + arg1 + v.x * 6 + v.y * c * 6;
}
