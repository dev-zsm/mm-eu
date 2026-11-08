#include "types.h"
#include "generated/code_funcs.h"

extern void Collider_SetElement(void *arg0, u8 *arg1, u8 *arg2);
extern void Collider_SetQuadDim(void *arg0, u8 *arg1, u8 *arg2);

s32 Collider_SetQuad(struct PlayState *play, struct ColliderQuad *dest, struct Actor *actor, struct ColliderQuadInit *src) {
    Collider_SetBase(play, dest, actor, src);
    Collider_SetElement(play, (u8 *)dest + 0x18, (u8 *)src + 8);
    Collider_SetQuadDim(play, (u8 *)dest + 0x40, (u8 *)src + 0x20);
    return 1;
}
