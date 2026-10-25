#include "types.h"

typedef struct {
    u8 pad0[0x18875];
    u8 unk18875;
    u8 pad18876[4];
    u16 unk1887A;
    u8 pad1887C[3];
    u8 unk1887F;
} PlayState;

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0x3CB0 - 0xC];
    s32 unk3CB0;
    u8 pad3CB4[0x3CE4 - 0x3CB4];
    u16 unk3CE4;
    u8 pad3CE6[0x3F55 - 0x3CE6];
    u8 unk3F55;
} Environment;

extern u8 D_801BE700;
extern Environment D_801E6EF0;

void Environment_WarpSongLeave(PlayState *play) {
    D_801BE700 = 0;
    D_801E6EF0.unk8 = 0;
    D_801E6EF0.unk3CB0 = -3;
    play->unk1887A = D_801E6EF0.unk3CE4;
    play->unk18875 = 0x14;
    play->unk1887F = 3;
    D_801E6EF0.unk3F55 = 3;
}
