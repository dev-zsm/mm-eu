// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/graph.h"

void Graph_ThreadEntry(void* arg) {
    GraphicsContext gfxCtx;
    GameStateOverlay* nextOvl = &gGameStateOverlayTable[0];

    PRINTF(T("グラフィックスレッド実行開始\n", "Start graphic thread execution\n"));

    gZBufferLoRes = malloc(sizeof(*gZBufferLoRes) + sizeof(*gWorkBufferLoRes) + 64 - 1);
    gZBufferLoRes = (void*)ALIGN64((uintptr_t)gZBufferLoRes);

    gWorkBufferLoRes = (void*)((u8*)gZBufferLoRes + sizeof(*gZBufferLoRes));

    gGfxSPTaskOutputBufferHiRes = gGfxSPTaskOutputBufferLoRes = malloc(sizeof(*gGfxSPTaskOutputBufferLoRes));

    gGfxSPTaskOutputBufferEndLoRes = (u8*)gGfxSPTaskOutputBufferLoRes + sizeof(*gGfxSPTaskOutputBufferLoRes);
    gGfxSPTaskOutputBufferEndHiRes = (u8*)gGfxSPTaskOutputBufferHiRes + sizeof(*gGfxSPTaskOutputBufferHiRes);

    SysCfb_Init();
    Fault_SetFrameBuffer(gWorkBuffer, SCREEN_WIDTH, SCREEN_HEIGHT);
    Graph_Init(&gfxCtx);

    while (nextOvl) {
        GameStateOverlay* ovl = nextOvl;
        GameState* gameState;
        size_t size;
        const char* name = "";
        s32 pad;

        Overlay_LoadGameState(ovl);

        size = ovl->instanceSize;

        name = ref_func_800809F4(ovl->file.vromStart);

        PRINTF(T("ゲームクラス %s サイズ＝%dバイト\n", "Game class %s Size = %d bytes\n"), name, size);

        gameState = malloc(size);

        bzero(gameState, size);
        GameState_Init(gameState, ovl->init, &gfxCtx);

        while (GameState_IsRunning(gameState)) {
            Graph_Update(&gfxCtx, gameState);
        }

        nextOvl = Graph_GetNextGameState(gameState);

        if (size) {}

        GameState_Destroy(gameState);
        free(gameState);

        Overlay_FreeGameState(ovl);
    }

    Graph_Destroy(&gfxCtx);

    PRINTF(T("グラフィックスレッド実行終了\n", "End of graphic thread execution\n"));
}
