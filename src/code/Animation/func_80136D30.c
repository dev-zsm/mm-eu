// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Anim;

s32 Animation_OnFrameImpl(Anim *anim, f32 frame, f32 updateRate) {
    f32 rate = anim->unk1C * updateRate;
    f32 cur = anim->unk18 - rate;
    f32 limit;

    if (cur < 0.0f) {
        cur += anim->unk14;
    } else if (cur >= anim->unk14) {
        cur -= anim->unk14;
    }
    if (frame == 0.0f && rate > 0.0f) {
        frame = anim->unk14;
    }
    limit = cur + rate - frame;
    if (limit * rate >= 0.0f && (limit - rate) * rate < 0.0f) {
        return 1;
    }
    return 0;
}
