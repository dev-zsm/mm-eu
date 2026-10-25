#include "types.h"

extern void Collider_SetBaseType1(void *arg0, void *arg1, void *arg2, void *arg3);
extern void Collider_SetElement(void *arg0, void *arg1, void *arg2);
extern void Collider_SetCylinderDim(void *arg0, void *arg1, void *arg2);

s32 Collider_SetCylinderType1(void *arg0, u8 *arg1, void *arg2, u8 *arg3) {
    Collider_SetBaseType1(arg0, arg1, arg2, arg3);
    Collider_SetElement(arg0, arg1 + 0x18, arg3 + 8);
    Collider_SetCylinderDim(arg0, arg1 + 0x40, arg3 + 0x20);
    return 1;
}
