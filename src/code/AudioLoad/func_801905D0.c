// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 unk2;
    u8 pad3[5];
    s32 unk8;
    s32 pad0C;
    s32 unk10;
    s32 pad14;
    s32 unk18;
} Inst;

extern Inst *AudioPlayback_GetInstrumentInner(s32, s32);
extern Inst *AudioPlayback_GetDrum(s32, s32);
extern void AudioLoad_SyncLoadSample(s32, s32);

s32 AudioLoad_SyncLoadInstrument(s32 a0, s32 a1, s32 a2) {
    Inst *i;

    if (a1 < 0x7F) {
        i = AudioPlayback_GetInstrumentInner(a0, a1);
        if (i == 0) {
            return -1;
        }
        if (i->unk1 != 0) {
            AudioLoad_SyncLoadSample(i->unk8, a0);
        }
        AudioLoad_SyncLoadSample(i->unk10, a0);
        if (i->unk2 != 0x7F) {
            AudioLoad_SyncLoadSample(i->unk18, a0);
        }
        return;
    }
    if (a1 == 0x7F) {
        i = AudioPlayback_GetDrum(a0, a2);
        if (i == 0) {
            return -1;
        }
        AudioLoad_SyncLoadSample(*(s32 *)((u8 *)i + 4), a0);
        return 0;
    }
}
