// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xA74];
    u32 unkA74;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} GlobalContext;

typedef struct {
    u8 pad0[0x114];
    u8 unk114;
} Actor;

s32 Actor_OtherIsTargeted(GlobalContext *globalCtx, Actor *actor) {
    Player *player = globalCtx->player;

    if (((player->unkA74 & 0x80000000) != 0) && (actor->unk114 == 0)) {
        return 1;
    }
    return 0;
}
