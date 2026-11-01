#include "types.h"
typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[0x10]; u32 unk10; } St;
Gfx *func_80188E90(Gfx *, s32);
Gfx *AudioSynth_FinalResample(Gfx *cmd, St *s, s32 a2, u16 a3, u16 a4, s32 a5) {
    register Gfx *out = cmd;
    Gfx *g;
    if (a3 == 0) {
        func_80188E90(out++, 0x3B0);
    } else {
        g = out++;
        g->w0 = 0x08000000 | a4;
        g->w1 = 0x03B00000 | (a2 & 0xFFFF);
        g = out++;
        g->w0 = 0x05000000 | ((a5 & 0xFF) << 16) | a3;
        g->w1 = s->unk10 + 0x20;
    }
    return out;
}
