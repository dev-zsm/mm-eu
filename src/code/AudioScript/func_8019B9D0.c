#include "types.h"

typedef struct {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 pad2C[0xC];
    /* 0x38 */ void *channels[16];
    /* 0x78 */ u8 pad78[0x1C];
    /* 0x94 */ void *unk94;
    /* 0x98 */ void *unk98;
    /* 0x9C */ u8 pad9C[0x44];
    /* 0xE0 */ s32 unkE0;
} SeqPlayer;

extern u8 D_801CE0E4[];
extern u8 D_801CE0F4[];
extern void AudioScript_SequencePlayerDisable();
extern void AudioScript_InitSequenceChannel(void *);

void AudioScript_ResetSequencePlayer(SeqPlayer *p) {
    s32 i;

    AudioScript_SequencePlayerDisable();
    p->flags &= ~2;
    p->unk10 = 0;
    p->unk1 = 1;
    p->unk12 = 0;
    p->unk14 = 0;
    p->unkA = 0;
    p->unk8 = 0x1680;
    p->unkC = 0;
    p->unkE = 0;
    p->unk2 = 0;
    p->unk94 = D_801CE0E4;
    p->unk98 = D_801CE0F4;
    p->unkE0 = 0;
    p->unk16 = 0;
    p->unk1C = 1.0f;
    p->unk20 = 0.0f;
    p->unk24 = 0.0f;
    p->unk28 = 0.5f;
    for (i = 0; i < 16; i++) {
        AudioScript_InitSequenceChannel(p->channels[i]);
    }
}
