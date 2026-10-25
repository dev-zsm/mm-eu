#include "types.h"

extern void Collider_SetBase(void *arg0, void *arg1, void *arg2, void *arg3);
extern void Collider_SetElement(void *arg0, u8 *arg1, u8 *arg2);
extern void Collider_SetQuadDim(void *arg0, u8 *arg1, u8 *arg2);

s32 Collider_SetQuad(void *arg0, u8 *arg1, void *arg2, u8 *arg3) {
    Collider_SetBase(arg0, arg1, arg2, arg3);
    Collider_SetElement(arg0, arg1 + 0x18, arg3 + 8);
    Collider_SetQuadDim(arg0, arg1 + 0x40, arg3 + 0x20);
    return 1;
}
