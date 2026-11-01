#include "types.h"

typedef struct {
    u8 pad0[0x1CCC];
    void *unk1CCC;
} GlobalContext;

typedef struct {
    u8 pad0[0xA6C];
    u32 unkA6C;
} Player;

typedef struct {
    u8 pad0[0x8C];
    GlobalContext *globalCtx;
    Player *player;
} Actor;

// ? instr differ: the ROM keeps the player pointer in v0 with a likely branch.
u32 func_800CB9B0(Actor *actor) {
    if (actor->player != actor->globalCtx->unk1CCC) {
        return 0;
    }
    return actor->player->unkA6C & 0x200000;
}
