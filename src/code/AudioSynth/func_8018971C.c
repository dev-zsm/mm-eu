// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Cmd;
typedef struct {
    u8 unk0;
    u8 pad1[0x26F];
    u32 unk270;
    u32 unk274;
    u8 pad278[8];
    u32 unk280;
    u32 unk284;
} Ctx;
Cmd *AudioSynth_FilterReverb(Cmd *cmd, s32 arg1, Ctx *ctx) {
    Cmd *a;
    Cmd *b;
    if (ctx->unk270 != 0) {
        a = cmd++;
        a->w0 = ((arg1 & 0xFFFF) | 0x7020000) | 0;
        a->w1 = ctx->unk270;
        b = cmd++;
        b->w0 = (((ctx->unk0 << 3) << 13) | 0x07000000) | 0xC70;
        b->w1 = ctx->unk280;
    }
    if (ctx->unk274 != 0) {
        a = cmd++;
        // one line: the ROM's scheduling depends on these stores sharing a single source line
        a->w0 = ((arg1 & 0xFFFF) | 0x7020000) | 0; a->w1 = ctx->unk274;
        b = cmd++;
        b->w0 = (((ctx->unk0 << 11) << 5) | 0x07000000) | 0xE10;
        b->w1 = ctx->unk284;
    }
    return cmd;
}
