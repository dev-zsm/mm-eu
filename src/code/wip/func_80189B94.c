#include "types.h"
typedef struct { u32 w0; u32 w1; } AudioCmd;
typedef struct { u8 pad0[0x28]; u8 *unk28; u8 *unk2C; } ReverbState;
AudioCmd *AudioSynth_SaveReverbSamplesImpl(AudioCmd *cmd, s32 a1, u16 a2, s32 a3, ReverbState *state) {
    u32 base = (((a3 >> 4) & 0xFF) << 16) | 0x15000000;
    AudioCmd *next;

    cmd->w0 = base | (a1 & 0xFFFF);
    cmd->w1 = (u32)(state->unk28 + a2 * 2);
    next = cmd + 1;
    next->w0 = base | ((a1 + 0x1A0) & 0xFFFF);
    next->w1 = (u32)(state->unk2C + a2 * 2);
    return next + 1;
}
