#include "types.h"

typedef struct {
    u8 pad0[0x70];
    f32 unk70;
    u8 pad74[0x1E4 - 0x74];
    s32 unk1E4;
    s16 unk1E8;
} Actor;

void Math_SmoothStepToF(f32 *pValue, f32 target, f32 fraction, f32 step, f32 minStep);
s32 SubS_CopyPointFromPath(s32 path, s16 idx, f32 *dst);
s32 SubS_MoveActorToPoint(Actor *actor, f32 *point, s16 rot);

s32 EnHy_MoveBackwards(Actor *arg0, f32 arg1) {
    s16 yaw;
    s32 ret = 0;
    f32 pt[3];

    Math_SmoothStepToF(&arg0->unk70, arg1, 0.4f, 1000.0f, 0.0f);
    yaw = (s32)(arg0->unk70 * 400.0f);
    if (SubS_CopyPointFromPath(arg0->unk1E4, arg0->unk1E8, pt) != 0 &&
        SubS_MoveActorToPoint(arg0, pt, yaw) != 0) {
        arg0->unk1E8--;
        if (arg0->unk1E8 < 0) {
            ret = 1;
        }
    }
    return ret;
}
