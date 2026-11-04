// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u32 flags;
    u8 pad8[0x728];
    s32 unk730;
    u8 pad734[0x354];
    s32 unkA88;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} GlobalContext;

s32 Actor_ChangeFocus(s32 a0, GlobalContext *globalCtx, s32 a2) {
    Player *player = globalCtx->player;
    s32 focus = player->unkA88;

    if ((player->flags & 0x100) != 0) {
        if (focus != 0) {
            player->unkA88 = a2;
            player->unk730 = a2;
            return 1;
        }
    }
    return 0;
}
