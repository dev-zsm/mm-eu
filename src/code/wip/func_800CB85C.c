#include "types.h"

typedef struct {
    u8 pad0[0x1CCC];
    void *unk1CCC;
} GlobalContext;

typedef struct {
    u8 pad0[0xADB];
    s8 unkADB;
} Player;

typedef struct {
    u8 pad0[0x8C];
    GlobalContext *globalCtx;
    Player *player;
} Actor;

// 5 instr differ: the ROM keeps the player pointer in v0 with a likely branch.
s32 func_800CB85C(Actor *actor) {
    if (actor->player != actor->globalCtx->unk1CCC) {
        return 0;
    }
    return actor->player->unkADB;
}
