// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 pad2[0x10];
    s16 unk12;
    u8 pad14[8];
    f32 unk1C;
    f32 unk20;
    u8 pad24[0x13C];
} FadeEntry; // size = 0x160

extern u8 D_801F84B0[];

void AudioThread_SetFadeOutTimer(s32 index, s32 timer) {
    FadeEntry *entry;

    if (timer == 0) {
        timer = 1;
    }
    entry = (FadeEntry *)((s32)(index * sizeof(FadeEntry) + 0x4460) + (s32)D_801F84B0);
    entry->unk1 = 2;
    entry->unk12 = timer;
    entry->unk20 = -(entry->unk1C / timer);
}
