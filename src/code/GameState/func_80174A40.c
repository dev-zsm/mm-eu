// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/game.h"

void GameState_Realloc(GameState* gameState, size_t size) {
    GameAlloc* alloc = &gameState->alloc;
    void* gameArena;
    size_t systemMaxFree;
    size_t bytesFree;
    size_t bytesAllocated;
    void* heapStart = gameState->tha.start;

    THA_Destroy(&gameState->tha);
    GameAlloc_Free(alloc, heapStart);
    GetFreeArena(&systemMaxFree, &bytesFree, &bytesAllocated);
    size = ((systemMaxFree - ARENA_NODE_SIZE) < size) ? 0 : size;
    if (size == 0) {
        size = systemMaxFree - ARENA_NODE_SIZE;
    }

    gameArena = GameAlloc_Malloc(alloc, size);
    if (gameArena != NULL) {
        THA_Init(&gameState->tha, gameArena, size);
    } else {
        THA_Init(&gameState->tha, NULL, 0);
        _dbg_hungup("../game.c", 1076);
    }
}
