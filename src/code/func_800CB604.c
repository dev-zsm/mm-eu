// FLAGS: -O2 -g3 -mips2

#include "types.h"

typedef struct {
    u8 pad0[0xA6C];
    u32 unkA6C;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player* player;
} GlobalContext;

typedef struct {
    u8 pad0[0x8C];
    GlobalContext* globalCtx;
    Player* player;
} Unk;

u32 func_800CB604(Unk* a0) {
    Player* player = a0->player;

    // the comma expression changes the ROM's branch (bnel vs bne); no plain form found
    if (a0->player == (0, a0->globalCtx)->player) {
        return player->unkA6C & 0x20;
    }
    return 0;
}
