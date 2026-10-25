#include "types.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x10];
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u8 pad16[6];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ u8 pad24[0x13C];
} AudioSeqPlayer; // size = 0x160

typedef struct {
    /* 0x0000 */ u8 pad0[0x4460];
    /* 0x4460 */ AudioSeqPlayer seqPlayers[1];
} AudioContext;

extern AudioContext D_801F84B0;

void AudioThread_SetFadeInTimer(s32 index, s32 timer) {
    AudioSeqPlayer *player;

    if (timer != 0) {
        player = &D_801F84B0.seqPlayers[index];
        player->unk1 = 1;
        player->unk14 = timer;
        player->unk12 = timer;
        player->unk1C = 0.0f;
        player->unk20 = 0.0f;
    }
}
