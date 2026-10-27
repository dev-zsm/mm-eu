// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} AudioCmd;

typedef struct {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
} ReverbState;

// Block-scoped command writer: the ROM keeps one pointer per command, which a plain cmd->w0 / cmd++ sequence folds away.
#define AUDIO_CMD(pkt, word0, word1) { AudioCmd *_c = (pkt); _c->w0 = (word0); _c->w1 = (word1); }

AudioCmd *AudioSynth_LeakReverb(AudioCmd *cmd, ReverbState *reverb) {
    AUDIO_CMD(cmd++, 0x0A000C70, 0x071001A0);
    AUDIO_CMD(cmd++, 0x0C1A0000 | (reverb->unk10 & 0xFFFF), 0x0E100C70);
    AUDIO_CMD(cmd++, 0x0C1A0000 | (reverb->unk12 & 0xFFFF), 0x07100E10);
    return cmd;
}
