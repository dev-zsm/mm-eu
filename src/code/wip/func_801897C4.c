// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0x2D0 - 5];
} Sub;

typedef struct {
    u8 pad0[1];
    s8 numSlots;
    u8 pad2[0x16];
    Sub subs[1];
} Ctx;

typedef struct {
    u8 pad0[5];
    s8 unk5;
    u8 pad6[2];
    s16 unk8;
} Cmd;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Ctx D_801F84B0;
Gfx *func_80188D38(Gfx *a, void *b, s16 c, Cmd *d);
Gfx *func_80188DE0(Gfx *g, void *b, s16 c, Cmd *d);

Gfx *AudioSynth_MixOtherReverbIndex(Gfx *gfx, Cmd *cmd, s16 arg2) {
    Gfx *g;
    Sub *sub;
    s32 idx = cmd->unk5;

    if (idx < D_801F84B0.numSlots) {
        sub = &D_801F84B0.subs[idx];
        if (sub->unk4 == 1) {
            g = func_80188D38(gfx, sub, arg2, cmd);
            g->w1 = 0x0C7003D0;
            g->w0 = (cmd->unk8 & 0xFFFF) | 0x0C340000;
            gfx = func_80188DE0(g + 1, sub, arg2, cmd);
        }
    }
    return gfx;
}
