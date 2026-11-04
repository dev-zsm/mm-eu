// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/game.h"

void GameState_Init(GameState* gameState, GameStateFunc init, GraphicsContext* gfxCtx) {
    PRINTF(T("\n***** game コンストラクタ開始 *****\n\n", "\n***** game constructor start *****\n\n"));

    gameState->gfxCtx = gfxCtx;
    gameState->frames = 0;
    gameState->main = NULL;
    gameState->destroy = NULL;
    gameState->running = true;
    gfxCtx->viMode = gActiveViMode;
    gfxCtx->viConfigFeatures = gViConfigFeatures;
    gfxCtx->xScale = gViConfigXScale;
    gfxCtx->yScale = gViConfigYScale;
    gameState->init = NULL;
    gameState->size = 0;

    {
        s32 requiredScopeTemp;

        GameAlloc_Init(&gameState->alloc);
    }

    GameState_InitArena(gameState, 0x100000);
    GameState_SetFramerateDivisor(gameState, 3);

    init(gameState);

    VisCvg_Init(&sGameVisCvg);
    VisZBuf_Init(&sGameVisZBuf);
    VisMono_Init(&sGameVisMono);
    ViMode_Init(&sGameViMode);
    SpeedMeter_Init(&sGameSpeedMeter);
    Rumble_Init();

    osSendMesg(&gameState->gfxCtx->queue, NULL, OS_MESG_BLOCK);

    PRINTF(T("\n***** game コンストラクタ終了 *****\n\n", "\n***** game constructor end *****\n\n"));
}
