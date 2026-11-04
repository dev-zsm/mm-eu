#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ void (*main)(void *);
    /* 0x08 */ void (*destroy)(void *);
    /* 0x0C */ u8 padC[0x98];
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ s32 unkA8;
} GameState;

extern void PreNMI_Main(void *);
extern void PreNMI_Destroy(void *);
extern void GameState_SetFramerateDivisor(GameState *gameState, s32 divisor);

void PreNMI_Init(GameState *gameState) {
    gameState->main = PreNMI_Main;
    gameState->destroy = PreNMI_Destroy;
    gameState->unkA4 = 0x1E;
    gameState->unkA8 = 0xA;
    GameState_SetFramerateDivisor(gameState, 1);
}
