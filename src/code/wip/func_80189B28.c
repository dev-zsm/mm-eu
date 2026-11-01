#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x28];
    u32 unk28;
    u32 unk2C;
} ReverbBuffers;

Gfx *AudioSynth_LoadReverbSamplesImpl(Gfx *cmd, u16 a, u16 b, s32 c, ReverbBuffers *buf) {
    u32 op = (((c >> 4) & 0xFF) << 16) | 0x14000000;
    u32 offset = (u16)b * 2;

    cmd->w0 = op | (u16)a;
    cmd->w1 = buf->unk28 + offset;
    cmd++;
    cmd->w0 = op | (u16)(a + 0x1A0);
    cmd->w1 = buf->unk2C + offset;
    return cmd + 1;
}
