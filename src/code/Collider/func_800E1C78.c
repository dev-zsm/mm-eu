#include "types.h"

extern void Collider_SetBaseType1(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3);
extern void Collider_SetElement(s32 arg0, u8 *arg1, u8 *arg2);
extern void Collider_SetQuadDim(s32 arg0, u8 *arg1, u8 *arg2);

s32 Collider_SetQuadType1(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    Collider_SetBaseType1(arg0, arg1, arg2, arg3);
    Collider_SetElement(arg0, arg1 + 0x18, arg3 + 0x8);
    Collider_SetQuadDim(arg0, arg1 + 0x40, arg3 + 0x20);
    return 1;
}
