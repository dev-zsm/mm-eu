// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u32 flags; u8 pad4[0xC4]; s8 v; } Sub;
typedef struct { u8 pad0[0x4460]; u32 flags; u8 pad4464[0x70]; Sub *sub; } Ch;
void AudioSeq_QueueSeqCmd(u32 a, u8 b, u8 c, u8 d);
extern u8 D_801F84B0[];
u8 func_801A4814(u8 a, u8 b) {
    u8 ret = 0xFF;
    Ch *ch = (Ch *)(D_801F84B0 + a * 0x160);
    if (ch->flags >> 31) {
        if (ch->sub->flags >> 31) {
            if (ch->sub->v != -1) {
                ret = ch->sub->v;
                if (b == 1) {
                    AudioSeq_QueueSeqCmd(((u32)a << 24) | 0x80000000 | 0xF00 | 0xFF, b, ret, a);
                }
            }
        }
    }
    return ret;
}
