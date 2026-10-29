#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;
typedef struct {
    u8 pad0[0x24];
    V3 unk24;
    u8 pad30[2];
    s16 unk32;
    u8 padBE[0xBE - 0x34];
    s16 unkBE;
} A;
extern void Actor_WorldToActorCoords(A *, V3 *, void *);
extern s16 SubS_GetDistSqAndOrientPoints(void *, V3 *, void *);
extern void Math_SmoothStepToS(s16 *, s16, s32, s16, s32);
extern void Actor_MoveWithGravity(A *);
s32 SubS_MoveActorToPoint(A *actor, void *point, s16 arg2) {
    V3 sp4C;
    V3 sp40;
    f32 sp3C;
    f32 sp38;
    s32 ret;
    Actor_WorldToActorCoords(actor, &sp4C, point);
    Math_SmoothStepToS(&actor->unk32, SubS_GetDistSqAndOrientPoints(point, &actor->unk24, &sp3C), 4, arg2, 1);
    actor->unkBE = actor->unk32;
    Actor_MoveWithGravity(actor);
    do { Actor_WorldToActorCoords(actor, &sp40, point); SubS_GetDistSqAndOrientPoints(point, &actor->unk24, &sp38); if ((sp4C.z > 0.0f) && (sp40.z <= 0.0f)) { ret = 1; } else { ret = 0; } return ret; } while (0);
}
