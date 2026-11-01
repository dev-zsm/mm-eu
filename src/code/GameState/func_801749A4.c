#include "types.h"
#include "code_funcs.h"
void GameState_IncrementFrameCount(void *a0) {
    GameState_Noop(a0);
    *(s32 *)((u8 *)a0 + 0x9C) += 1;
}
