#include "types.h"

typedef struct { u8 pad0[0x74]; u8 tha[4]; s32 unk78; u8 pad7C[8]; u8 alloc[1]; } GameState;
void THA_Destroy(void *a);
void GameAlloc_Free(void *a, s32 b, void *c);
void THA_Init(void *a, s32 b, u32 c);
s32 GameAlloc_Malloc(void *a, u32 b);
void func_80086F3C(s32 *a, s32 *b, s32 *c);
void func_800862F0(void *a, s32 b);
extern u8 D_801D755C[];

void GameState_Realloc(GameState *gs, u32 size) {
    void *tha;
    s32 mem;
    s32 sp34[3];
    s32 unk78;
    void *alloc;
    tha = gs->tha;
    unk78 = gs->unk78;
    THA_Destroy(tha);
    alloc = gs->alloc;
    GameAlloc_Free(alloc, unk78, gs);
    func_80086F3C(&sp34[2], &sp34[1], &sp34[0]);
    mem = sp34[2] - 0x10;
    if (mem < size) {
        size = 0;
    }
    if (size == 0) {
        size = mem;
    }
    mem = GameAlloc_Malloc(alloc, size);
    if (mem != 0) {
        THA_Init(tha, mem, size);
        return;
    }
    THA_Init(tha, 0, 0);
    func_800862F0(D_801D755C, 0x434);
}
