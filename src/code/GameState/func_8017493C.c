#include "types.h"

typedef struct GameState {
    /* 0x0 */ void *gfxCtx;
    /* 0x4 */ void (*main)(struct GameState *);
} GameState;

typedef struct {
    u8 pad0[0x190];
    s16 unk190;
} DebugState;

extern DebugState *D_801EB7E0;

extern void GameState_SetFrameBuffer(void *gfxCtx);
extern void GameState_Draw(GameState *gameState, void *gfxCtx);
extern void GameState_DrawEnd(void *gfxCtx);

void GameState_Update(GameState *gameState) {
    void *gfxCtx = gameState->gfxCtx;

    GameState_SetFrameBuffer(gfxCtx);
    gameState->main(gameState);
    if (D_801EB7E0->unk190 != 2) {
        GameState_Draw(gameState, gfxCtx);
        GameState_DrawEnd(gfxCtx);
    }
}
