#include "types.h"
#include "generated/overlays/0477.h"

extern u8 D_80B1577C[];

void func_80000F1C(ObjSpidertent *this) {
    *(u32 *)((u8 *)this + 4) |= 0x10;
    *(u8 **)((u8 *)this + 0x3C8) = D_80B1577C;
}
