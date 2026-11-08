#include "types.h"
#include "generated/code_funcs.h"

extern void Collider_SetBaseType1(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3);
extern void Collider_SetElement(s32 arg0, u8 *arg1, u8 *arg2);
extern void Collider_SetQuadDim(s32 arg0, u8 *arg1, u8 *arg2);

s32 Collider_SetQuadType1(struct PlayState *play, struct ColliderQuad *dest, struct Actor *actor, struct ColliderQuadInitType1 *src) {
    Collider_SetBaseType1(play, dest, actor, src);
    Collider_SetElement(play, (u8 *)dest + 0x18, (u8 *)src + 0x8);
    Collider_SetQuadDim(play, (u8 *)dest + 0x40, (u8 *)src + 0x20);
    return 1;
}
