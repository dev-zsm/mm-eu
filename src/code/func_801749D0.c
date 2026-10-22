// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_800862F0(void *, s32);
void THA_Init(s32, s32, s32, s32);
s32 GameAlloc_Malloc(s32, s32, s32);
extern u8 D_801D7550[];

void GameState_InitArena(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = GameAlloc_Malloc(arg0 + 0x84, arg1, arg2);
    if (temp_v0 != 0) {
        THA_Init(arg0 + 0x74, temp_v0, arg1, arg0);
        return;
    }
    THA_Init(arg0 + 0x74, 0, 0, arg0);
    func_800862F0(D_801D7550, 0x40D);
}
