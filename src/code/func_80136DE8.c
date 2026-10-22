// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Animation_OnFrameImpl(void *, f32, f32);
extern f32 D_801C9E18;

void PlayerAnimation_OnFrame(void *a0, f32 a1) {
    f32 tmp = D_801C9E18;
    Animation_OnFrameImpl(a0, a1, tmp);
}
