#include "types.h"
typedef struct { u8 pad0[0x70]; f32 f70; u8 pad74[0x1E4 - 0x74]; u8 *p1E4; s16 s1E8; } Act;
void Math_SmoothStepToF(f32 *a, f32 b, f32 c, f32 d, f32 e);
s32 SubS_CopyPointFromPath(u8 *a, s16 b, void *c);
s32 SubS_MoveActorToPoint(void *a, void *b, s16 c);
s32 EnHy_MoveForwards(Act *a, f32 speed) {
    s16 v;
    s32 ret = 0;
    u8 pad[0xC];
    Math_SmoothStepToF(&a->f70, speed, 0.4f, 1000.0f, 0.0f);
    v = a->f70 * 400.0f;
    if (SubS_CopyPointFromPath(a->p1E4, a->s1E8, pad) != 0) {
        if (SubS_MoveActorToPoint(a, pad, v) != 0) {
            a->s1E8++;
            if (a->s1E8 >= *a->p1E4) {
                ret = 1;
            }
        }
    }
    return ret;
}
