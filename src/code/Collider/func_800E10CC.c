#include "types.h"

extern void Collider_SetBase(s32 a0, s32 a1, s32 a2, s32 a3);
extern void Collider_SetElement(s32 a0, s32 a1, s32 a2);
extern void Collider_SetCylinderDim(s32 a0, s32 a1, s32 a2);

s32 Collider_SetCylinder(s32 a0, s32 a1, s32 a2, s32 a3) {
    Collider_SetBase(a0, a1, a2, a3);
    Collider_SetElement(a0, a1 + 0x18, a3 + 8);
    Collider_SetCylinderDim(a0, a1 + 0x40, a3 + 0x20);
    return 1;
}
