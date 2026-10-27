#include "types.h"

typedef struct {
    u8 pad0[8];
    u16 unk8;
} Entry;

typedef struct {
    u8 pad0[0x1F4C];
    Entry *entries[1];
} Ctx;

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
    u8 pad34[0x8A];
    s16 unkBE;
} Actor;

extern void Cutscene_ActorTranslate(Actor *actor, Ctx *ctx, s32 index);

void Cutscene_ActorTranslateAndYaw(Actor *actor, Ctx *ctx, s32 index) {
    Cutscene_ActorTranslate(actor, ctx, index);
    actor->unk32 = ctx->entries[index]->unk8;
    actor->unkBE = actor->unk32;
}
