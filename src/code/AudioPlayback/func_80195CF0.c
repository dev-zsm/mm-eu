// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { s32 w[8]; } Blk;

typedef struct {
    u8 pad0[0x28];
    u8 unk28;
    u8 pad29[3];
    s32 unk2C;
    u8 pad30[0x30];
    struct { u8 pad[0x84]; s32 unk84; } *unk60;
} Src;

typedef struct {
    u8 pad0[0x38];
    u8 unk38;
    u8 pad39[0x0F];
    Src *unk48;
    u8 pad4C[0x1C];
    u8 unk68;
    u8 pad69[0x6F];
    Blk unkD8;
} Note;

extern Blk D_801CE134;
extern void AudioEffects_InitAdsr(u8 *a, s32 b, u8 *c, Note *d);

void AudioPlayback_NoteInit(Note *arg0) {
    Src *s = arg0->unk48;

    if (s->unk28 == 0) {
        AudioEffects_InitAdsr(&arg0->unk68, s->unk60->unk84, &arg0->unk38 + 2, arg0);
    } else {
        AudioEffects_InitAdsr(&arg0->unk68, s->unk2C, &arg0->unk38 + 2, arg0);
    }
    arg0->unk38 = 0;
    arg0->unk68 = (arg0->unk68 & 0xFFF0) | 1;
    arg0->unkD8 = D_801CE134;
}
