// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0094.h"

extern void func_800FD0AC(s32, f32, f32, f32, f32);

void EnMThunder_AdjustLights(PlayState *play, f32 arg1) {
    func_800FD0AC(play, arg1, 850.0f, 0.2f, 0.0f);
}
