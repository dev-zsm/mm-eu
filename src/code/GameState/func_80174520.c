// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801C9E10;
extern f32 D_801C9E14;
extern f32 D_801C9E18;
extern f32 D_801C9E1C;

void GameState_UpdateFramerateDivisors(s32 arg0) {
    f32 temp_f0;

    D_801C9E10 = arg0;
    temp_f0 = (f32) arg0;
    D_801C9E14 = temp_f0;
    D_801C9E18 = temp_f0 * 0.5f;
    D_801C9E1C = temp_f0 / 3.0f;
}
