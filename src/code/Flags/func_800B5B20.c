#include "types.h"

typedef struct {
    u8 pad0[0x1E58];
    u32 switchFlags[4];
} SwitchFlagsCtx;

s32 Flags_GetSwitch(SwitchFlagsCtx *ctx, s32 flag) {
    if ((flag >= 0) && (flag < 0x80)) {
        return ctx->switchFlags[(flag & ~0x1F) >> 5] & (1 << (flag & 0x1F));
    }
    return 0;
}
