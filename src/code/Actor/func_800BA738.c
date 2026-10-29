#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ void *head;
} Item;

typedef struct {
    /* 0x000 */ u8 pad0[0x2C];
    /* 0x02C */ void *unk2C;
    /* 0x030 */ u8 pad30[0x220];
    /* 0x250 */ void *unk250;
} Ctx;

extern u8 D_801E5120[];
extern void func_80081B34(void *);
extern void Actor_Delete(Ctx *, void *, void *);
extern void ZeldaArena_Free(void *);
extern void func_8016AEC8(void *);
extern void func_800BF8C0();

void Actor_CleanupContext(Ctx *ctx, void *play) {
    s32 i;
    Item *it;
    void *a;

    func_80081B34(D_801E5120);
    for (i = 0; i < 12; i++) {
        if (i != 2) {
            it = (Item *)((u8 *)ctx + i * 12);
            a = it->head;
            while (a != NULL) {
                Actor_Delete(ctx, a, play);
                a = it->head;
            }
        }
    }
    a = ctx->unk2C;
    while (a != NULL) {
        Actor_Delete(ctx, a, play);
        a = ctx->unk2C;
    }
    if (ctx->unk250 != NULL) {
        ZeldaArena_Free(ctx->unk250);
        ctx->unk250 = NULL;
    }
    func_8016AEC8(play);
    func_800BF8C0();
}
