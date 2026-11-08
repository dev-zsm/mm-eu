#include "types.h"
#include "generated/code_funcs.h"

extern void Collider_SetBaseType1(void *arg0, void *arg1, void *arg2, void *arg3);
extern void Collider_SetElement(void *arg0, void *arg1, void *arg2);
extern void Collider_SetCylinderDim(void *arg0, void *arg1, void *arg2);

s32 Collider_SetCylinderType1(struct PlayState *play, struct ColliderCylinder *dest, struct Actor *actor, struct ColliderCylinderInitType1 *src) {
    Collider_SetBaseType1(play, dest, actor, src);
    Collider_SetElement(play, (u8 *)dest + 0x18, (u8 *)src + 8);
    Collider_SetCylinderDim(play, (u8 *)dest + 0x40, (u8 *)src + 0x20);
    return 1;
}
