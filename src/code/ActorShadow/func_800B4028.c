// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"

extern u8 D_4077480[];

void ActorShadow_DrawHorse(s32 a0, s32 a1, s32 a2) {
    ActorShadow_Draw(a0, a1, a2, D_4077480, 0);
}
