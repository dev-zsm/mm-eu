#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 unk14B;
} Inner;
typedef struct {
    u8 pad0[0x1CCC];
    Inner *unk1CCC;
} Ctx;
s32 MsgEvent_CheckZora(s32 arg0, Ctx *ctx, u8 **cursor, s32 arg3) {
    Inner *inner = ctx->unk1CCC;
    u8 *p = *cursor;
    s16 offset = (*cursor)[2] | (p[1] << 8);
    if (0) { }
    if (inner->unk14B == 2) {
        *cursor = (u8 *) (((s32) (*cursor)) + offset);
    }
    return 0;
}
