#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x32];
    /* 0x38 */ struct Chan *channels[16];
} SeqPlayer;

typedef struct Chan {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[3];
    /* 0x07 */ u8 unk7;
} Chan;

void AudioScript_SequencePlayerSetupChannels(SeqPlayer *p, u16 bits) {
    s32 i;
    Chan *c;

    for (i = 0; i < 16; i++) {
        if (bits & 1) {
            c = p->channels[i];
            c->unk7 = p->unk5;
            c->unk3 = p->unk3;
            c->unk2 = p->unk2;
        }
        bits = (s32)bits >> 1;
    }
}
