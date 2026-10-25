#include "types.h"

typedef struct {
    u8 pad0[0x1E74];
    u32 collectibleFlags[4];
} CollectibleFlagsCtx;

s32 Flags_GetCollectible(CollectibleFlagsCtx *ctx, s32 flag) {
    // Masking before the shift reproduces the ROM's index computation.
    if ((flag > 0) && (flag < 0x80)) {
        return ctx->collectibleFlags[(flag & ~0x1F) >> 5] & (1 << (flag & 0x1F));
    }
    return 0;
}
