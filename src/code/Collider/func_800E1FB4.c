// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void Collider_SetElement(s32, s32, s32);
void Collider_SetJntSphElementDim(s32, s32, s32);

s32 Collider_SetSphere(struct PlayState *play, struct ColliderSphere *dest, struct Actor *actor, struct ColliderSphereInit *src) {
    Collider_SetBase(play, dest, actor, src);
    Collider_SetElement(play, (u8 *)dest + 0x18, (u8 *)src + 8);
    Collider_SetJntSphElementDim(play, (u8 *)dest + 0x40, (u8 *)src + 0x20);
    return 1;
}
