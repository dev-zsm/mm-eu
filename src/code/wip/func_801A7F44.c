// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad0[0x26]; u8 unk26; u8 pad27[2]; u8 unk29; u8 unk2A; u8 pad2B[5]; } Chan;
typedef struct { u8 pad0[0x22]; s16 unk22; u8 pad24[8]; } Cmd;
extern Chan *D_801D3DA8[];
extern void AudioThread_QueueCmdS8(s32, s32);
extern void AudioSfx_RemoveMatchingRequests(s32, void *);
extern void AudioSfx_RemoveBankEntry(u8, u8);
void AudioSfx_StopByBank(u8 bank) {
    Cmd cmd;
    s32 i;
    Chan *c;

    i = D_801D3DA8[bank]->unk29;
    while (i != 0xFF) {
        c = (Chan *)((u8 *)D_801D3DA8[bank] + i * 0x30);
        if (c->unk26 >= 3) {
            AudioThread_QueueCmdS8((c->unk2A << 8) | 0x06020000, 0);
        }
        if (c->unk26 != 0) {
            AudioSfx_RemoveBankEntry(bank, i);
        }
        i = D_801D3DA8[bank]->unk29;
    }
    cmd.unk22 = bank << 12;
    AudioSfx_RemoveMatchingRequests(0, &cmd);
}
