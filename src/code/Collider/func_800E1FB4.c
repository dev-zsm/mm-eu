// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Collider_SetBase(s32, s32, s32, s32);
void Collider_SetElement(s32, s32, s32);
void Collider_SetJntSphElementDim(s32, s32, s32);

s32 Collider_SetSphere(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Collider_SetBase(arg0, arg1, arg2, arg3);
    Collider_SetElement(arg0, arg1 + 0x18, arg3 + 8);
    Collider_SetJntSphElementDim(arg0, arg1 + 0x40, arg3 + 0x20);
    return 1;
}
