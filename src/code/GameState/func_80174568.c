#include "types.h"
extern u8 *D_801EB7E0;
extern void GameState_UpdateFramerateDivisors();
void GameState_SetFramerateDivisor(u8 *a0, s32 a1) {
    *(u16 *)(D_801EB7E0 + 0x110) = a1;
    a0[0xA2] = a1;
    GameState_UpdateFramerateDivisors(a1);
}
